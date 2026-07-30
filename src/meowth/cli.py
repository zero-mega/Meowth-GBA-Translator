"""Meowth CLI - GBA Pokemon translation tool."""

from pathlib import Path

import click

from .core import TranslationCallbacks, TranslationConfig, TranslationEngine
from .languages import validate_language
from .pipeline import Pipeline
from .translator import PROVIDER_PRESETS


def _load_env():
    """Load .env file if present."""
    env_path = Path(__file__).parent.parent.parent / ".env"
    if env_path.exists():
        for line in env_path.read_text().splitlines():
            line = line.strip()
            if line and not line.startswith("#") and "=" in line:
                key, val = line.split("=", 1)
                import os
                os.environ.setdefault(key.strip(), val.strip())


def _load_config() -> dict:
    """Load meowth.toml config if present."""
    config_path = Path(__file__).parent.parent.parent / "meowth.toml"
    if not config_path.exists():
        return {}
    try:
        import tomllib
    except ImportError:
        import tomli as tomllib  # type: ignore[no-redef]
    return tomllib.loads(config_path.read_text(encoding="utf-8"))


def _provider_kwargs(provider, api_base, api_key_env, model) -> dict:
    """Build provider kwargs from CLI options, falling back to meowth.toml."""
    cfg = _load_config()
    t = cfg.get("translation", {})
    api_cfg = t.get("api", {})

    return {
        "provider": provider or t.get("provider"),
        "api_base": api_base or api_cfg.get("base_url"),
        "api_key_env": api_key_env or api_cfg.get("key_env"),
        "model": model or t.get("model"),
    }


def _get_language(cli_value, cli_default, config_key) -> str:
    """Get language from CLI or config, preferring config if CLI is default."""
    cfg = _load_config()
    t = cfg.get("translation", {})
    # If CLI value is not the default, use it; otherwise use config
    if cli_value != cli_default:
        return cli_value
    return t.get(config_key, cli_default)


# Shared CLI options for LLM provider configuration
_provider_options = [
    click.option("--provider", default=None, type=click.Choice(sorted(PROVIDER_PRESETS.keys()), case_sensitive=False),
                 help="LLM provider preset (e.g. openai, deepseek, google)"),
    click.option("--api-base", default=None, help="Custom API base URL (OpenAI-compatible)"),
    click.option("--api-key-env", default=None, help="Environment variable name for API key"),
    click.option("--model", default=None, help="Model name to use"),
]


def add_provider_options(func):
    """Decorator to add all provider options to a click command."""
    for option in reversed(_provider_options):
        func = option(func)
    return func


class CLICallbacks(TranslationCallbacks):
    """CLI implementation of translation callbacks."""

    def on_log(self, level: str, message: str):
        """Output log messages to the terminal."""
        if level == "error":
            click.secho(message, fg="red", err=True)
        elif level == "warning":
            click.secho(message, fg="yellow")
        else:
            click.echo(message)

    def on_progress(self, stage: str, current: int, total: int, message: str):
        """Output progress updates to the terminal."""
        # Progress is already included in log messages
        pass

    def on_stage_change(self, stage: str, status: str):
        """Handle stage changes (not needed for CLI)."""
        pass

    def on_error(self, error: Exception):
        """Output errors to the terminal."""
        click.secho(f"Error: {error}", fg="red", err=True)


@click.group()
def main():
    """Meowth - GBA Pokemon ROM translation tool."""
    _load_env()


@main.command()
@click.argument("rom_path", type=click.Path(exists=True))
@click.option("-o", "--output", default="work/texts.json", help="Output texts JSON path")
@click.option("--source", default="en", help="Source language code (default: from config or en)")
@click.option("--target", default="zh-Hans", help="Target language code (default: from config or zh-Hans)")
def extract(rom_path, output, source, target):
    """Extract texts from ROM using MeowthBridge."""
    source = _get_language(source, "en", "source_language")
    target = _get_language(target, "zh-Hans", "target_language")
    validate_language(source)
    validate_language(target)
    TranslationEngine.extract_texts(Path(rom_path), Path(output))
    click.echo(f"Extracted: {output}")


@main.command()
@click.argument("texts_json", type=click.Path(exists=True))
@click.option("-o", "--output", default="work/texts_translated.json")
@click.option("--batch-size", default=30, help="Texts per LLM batch")
@click.option("--workers", default=10, help="Parallel translation threads")
@click.option("--source", default="en", help="Source language code (default: from config or en)")
@click.option("--target", default="zh-Hans", help="Target language code (default: from config or zh-Hans)")
@add_provider_options
def translate(texts_json, output, batch_size, workers, source, target,
              provider, api_base, api_key_env, model):
    """Translate extracted texts JSON via LLM API."""
    source = _get_language(source, "en", "source_language")
    target = _get_language(target, "zh-Hans", "target_language")
    validate_language(source)
    validate_language(target)
    kwargs = _provider_kwargs(provider, api_base, api_key_env, model)

    config = TranslationConfig(
        source_lang=source,
        target_lang=target,
        batch_size=batch_size,
        max_workers=workers,
        **kwargs
    )
    engine = TranslationEngine(config, CLICallbacks())
    engine.translate_texts(Path(texts_json), Path(output))
    click.echo(f"Translated: {output}")


@main.command()
@click.argument("rom_path", type=click.Path(exists=True))
@click.option("--translations", required=True, type=click.Path(exists=True))
@click.option("-o", "--output", required=True)
@click.option("--source", default="en", help="Source language code (default: from config or en)")
@click.option("--target", default="zh-Hans", help="Target language code (default: from config or zh-Hans)")
def build(rom_path, translations, output, source, target):
    """Build translated ROM from translations."""
    source = _get_language(source, "en", "source_language")
    target = _get_language(target, "zh-Hans", "target_language")
    validate_language(source)
    validate_language(target)

    config = TranslationConfig(source_lang=source, target_lang=target)
    engine = TranslationEngine(config, CLICallbacks())
    engine.build_rom(Path(rom_path), Path(translations), Path(output))


@main.command()
@click.argument("rom_path", type=click.Path(exists=True))
@click.option("-o", "--output-dir", default="outputs")
@click.option("--work-dir", default="work")
@click.option("--source", default="en", help="Source language code (default: from config or en)")
@click.option("--target", default="zh-Hans", help="Target language code (default: from config or zh-Hans)")
@add_provider_options
def full(rom_path, output_dir, work_dir, source, target,
         provider, api_base, api_key_env, model):
    """Run full pipeline: extract -> translate -> build ROM."""
    source = _get_language(source, "en", "source_language")
    target = _get_language(target, "zh-Hans", "target_language")
    validate_language(source)
    validate_language(target)
    kwargs = _provider_kwargs(provider, api_base, api_key_env, model)

    config = TranslationConfig(
        source_lang=source,
        target_lang=target,
        rom_path=Path(rom_path),
        output_dir=Path(output_dir),
        work_dir=Path(work_dir),
        **kwargs
    )
    engine = TranslationEngine(config, CLICallbacks())
    engine.run_full()


@main.command("decomp-extract")
@click.argument("source_root", type=click.Path(exists=True, file_okay=False))
@click.option("-o", "--output", default="work/decomp_texts.json", help="Output texts JSON path")
def decomp_extract(source_root, output):
    """Extract texts from a pokeemerald-style decomp source tree."""
    from .decomp import write_extract

    data = write_extract(Path(source_root), Path(output))
    click.echo(f"Extracted {len(data['entries'])} strings → {output}")


@main.command("decomp-apply")
@click.argument("source_root", type=click.Path(exists=True, file_okay=False))
@click.option("--translations", required=True, type=click.Path(exists=True))
@click.option(
    "--output-root",
    default=None,
    type=click.Path(file_okay=False),
    help="Write modified sources here (default: modify source_root in place)",
)
def decomp_apply(source_root, translations, output_root):
    """Apply translated JSON back into a decomp source tree."""
    import json

    from .decomp import apply_decomp_translations

    data = json.loads(Path(translations).read_text(encoding="utf-8"))
    summary = apply_decomp_translations(
        Path(source_root),
        data,
        Path(output_root) if output_root else None,
    )
    click.echo(
        f"Applied {summary['strings_applied']} strings across "
        f"{summary['files_changed']} files → {summary['output_root']}"
    )


@main.command("decomp-full")
@click.argument("source_root", type=click.Path(exists=True, file_okay=False))
@click.option("-o", "--output-root", default="outputs/decomp_fr", help="Translated source tree")
@click.option("--work-dir", default="work")
@click.option("--source", default="en", help="Source language code (default: from config or en)")
@click.option("--target", default="fr", help="Target language code (default: from config or fr)")
@click.option("--batch-size", default=30, help="Texts per LLM batch")
@click.option("--workers", default=10, help="Parallel translation threads")
@click.option(
    "--glossary-only",
    is_flag=True,
    help="Only apply PokeAPI glossary to name tables (no LLM dialogue translation)",
)
@add_provider_options
def decomp_full(source_root, output_root, work_dir, source, target,
                batch_size, workers, glossary_only,
                provider, api_base, api_key_env, model):
    """Full decomp pipeline: extract → translate → write French (or other) sources."""
    import json
    import shutil

    from .decomp import apply_decomp_translations, write_extract
    from .core.engine import TABLE_CATEGORIES, convert_format

    source = _get_language(source, "en", "source_language")
    target = _get_language(target, "fr", "target_language")
    validate_language(source)
    validate_language(target)
    kwargs = _provider_kwargs(provider, api_base, api_key_env, model)

    work = Path(work_dir)
    work.mkdir(parents=True, exist_ok=True)
    texts_json = work / "decomp_texts.json"
    translated_json = work / "decomp_texts_translated.json"

    click.echo(f"Extracting from {source_root}…")
    data = write_extract(Path(source_root), texts_json)
    click.echo(f"  {len(data['entries'])} strings")

    config = TranslationConfig(
        source_lang=source,
        target_lang=target,
        batch_size=batch_size,
        max_workers=workers,
        work_dir=work,
        **kwargs,
    )
    engine = TranslationEngine(config, CLICallbacks())
    if glossary_only:
        click.echo(f"Glossary-only localization {source} → {target}…")
        converted = convert_format(data)
        for table in converted["tables"]:
            if table["category"] in TABLE_CATEGORIES:
                engine._translate_table(table)
        for entry in converted["free_texts"]:
            entry.setdefault("translated", entry["original"])
        translated_json.write_text(
            json.dumps(converted, ensure_ascii=False, indent=2), encoding="utf-8"
        )
    else:
        click.echo(f"Translating {source} → {target}…")
        engine.translate_texts(texts_json, translated_json)

    out = Path(output_root)
    if out.resolve() != Path(source_root).resolve():
        if out.exists():
            shutil.rmtree(out)
        click.echo(f"Copying source tree → {out}…")
        shutil.copytree(
            source_root,
            out,
            ignore=shutil.ignore_patterns(
                ".git", "build", "*.o", "*.i", "*.ii", "*.s", "*.exe"
            ),
        )
        apply_root = out
    else:
        apply_root = Path(source_root)

    translated = json.loads(translated_json.read_text(encoding="utf-8"))
    # Preserve extract metadata (path/kind/meta) lost when convert_format runs
    by_id = {e["id"]: e for e in data["entries"]}
    flat = []
    for table in translated.get("tables", []):
        flat.extend(table.get("entries", []))
    flat.extend(translated.get("free_texts", translated.get("entries", [])))
    for entry in flat:
        meta_src = by_id.get(entry.get("id"), {})
        for key in ("path", "kind", "meta", "category"):
            if key not in entry and key in meta_src:
                entry[key] = meta_src[key]

    summary = apply_decomp_translations(apply_root, {"entries": flat}, apply_root)
    click.echo(
        f"Done: {summary['strings_applied']} strings in "
        f"{summary['files_changed']} files → {summary['output_root']}"
    )


if __name__ == "__main__":
    main()
