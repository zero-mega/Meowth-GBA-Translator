"""Tests for pokeemerald-style decomp extract/apply."""

from pathlib import Path

from meowth.decomp import (
    apply_decomp_translations,
    extract_decomp_texts,
)


def _write(p: Path, text: str) -> None:
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_text(text, encoding="utf-8")


def test_asm_roundtrip(tmp_path: Path):
    src = (
        "Foo_Text::\n"
        '\t.string "Hello,\\n"\n'
        '\t.string "world!$"\n'
        "\n"
        "Bar_Text:\n"
        '\t.string "Bye.$"\n'
    )
    _write(tmp_path / "data/text/sample.inc", src)

    data = extract_decomp_texts(tmp_path)
    assert len(data["entries"]) == 2
    by_id = {e["id"]: e for e in data["entries"]}
    assert "Hello,\\nworld!" in by_id["asm:data/text/sample.inc:Foo_Text"]["original"]

    for e in data["entries"]:
        e["translated"] = e["original"].replace("Hello", "Bonjour").replace("Bye", "Salut")

    apply_decomp_translations(tmp_path, data, tmp_path)
    out = (tmp_path / "data/text/sample.inc").read_text(encoding="utf-8")
    assert "Bonjour" in out
    assert "Salut" in out


def test_c_macro_and_multiline(tmp_path: Path):
    _write(
        tmp_path / "src/data/text/species_names.h",
        'const u8 gSpeciesNames[][11] = {\n'
        '    [SPECIES_BULBASAUR] = _("BULBASAUR"),\n'
        "};\n",
    )
    _write(
        tmp_path / "src/data/text/item_descriptions.h",
        "static const u8 sBallDesc[] = _(\n"
        '    "A tool used for\\n"\n'
        '    "catching POKéMON.");\n',
    )

    data = extract_decomp_texts(tmp_path)
    kinds = {e["kind"] for e in data["entries"]}
    assert "c_macro" in kinds
    assert "c_multiline" in kinds

    for e in data["entries"]:
        if e["kind"] == "c_macro":
            e["translated"] = "BULBIZARRE"
        else:
            e["translated"] = "Un outil pour\\nattraper des POKéMON."

    apply_decomp_translations(tmp_path, data, tmp_path)
    species = (tmp_path / "src/data/text/species_names.h").read_text(encoding="utf-8")
    assert "BULBIZARRE" in species
    items = (tmp_path / "src/data/text/item_descriptions.h").read_text(encoding="utf-8")
    assert "attraper" in items
