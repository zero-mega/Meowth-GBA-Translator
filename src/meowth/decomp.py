"""Extract and apply translations for pokeemerald-style decomp sources.

Targets projects like Pokémon Heart & Soul that store dialogue in
``.string`` assembler directives and C ``_()`` macros rather than a
binary ROM alone.
"""

from __future__ import annotations

import json
import re
from dataclasses import dataclass
from pathlib import Path

# Labeled string blocks: Label: / Label:: followed by one or more .string lines
_LABEL_RE = re.compile(r"^([A-Za-z_][\w]*)::?\s*$")
_STRING_LINE_RE = re.compile(r'^(\s*)\.string\s+"((?:\\.|[^"\\])*)"(.*)$')
# C/C++ style _("text") — single-line form
_C_STRING_RE = re.compile(r'_\(\s*"((?:\\.|[^"\\])*)"\s*\)')
# Multi-line form: _(\n  "a\n"\n  "b");  (adjacent C string literals)
_C_MULTILINE_START_RE = re.compile(r'_\(\s*$')
_C_FRAGMENT_RE = re.compile(r'^\s*"((?:\\.|[^"\\])*)"\s*(\)\s*;?)?\s*$')

# Relative path → Meowth table category for glossary-backed names
_PATH_CATEGORIES: list[tuple[str, str]] = [
    ("src/data/text/species_names.h", "pokemon_names"),
    ("src/data/text/move_names.h", "move_names"),
    ("src/data/text/nature_names.h", "nature_names"),
    ("src/data/text/abilities.h", "ability_names"),
    ("src/data/items.h", "item_names"),
]

_SKIP_DIR_PARTS = {
    "build",
    ".git",
    "graphics",
    "sound",
    "tools",
    "docs",
}


@dataclass
class SourceSpan:
    """One extractable string and where it lives in the source tree."""

    entry_id: str
    path: str  # repo-relative posix path
    kind: str  # "asm_block" | "c_macro"
    original: str
    category: str
    # asm_block: line index of label, first/last .string line (inclusive)
    # c_macro: line index, match start/end within that line
    meta: dict


def _rel(path: Path, root: Path) -> str:
    return path.resolve().relative_to(root.resolve()).as_posix()


def _category_for(rel_path: str, original: str) -> str:
    for suffix, cat in _PATH_CATEGORIES:
        if rel_path.endswith(suffix) or rel_path == suffix:
            # abilities.h mixes names and descriptions; short ALLCAPS-ish → name
            if cat == "ability_names":
                plain = re.sub(r"\\[npl.]", "", original)
                if len(plain) <= 16 and plain == plain.upper() and any(c.isalpha() for c in plain):
                    return "ability_names"
                return "ability_descriptions"
            if cat == "item_names":
                # items.h is huge; only treat short name-like _() as item names
                plain = re.sub(r"\\[npl.]", "", original)
                if len(plain) <= 16:
                    return "item_names"
                return "item_descriptions"
            return cat
    if "/maps/" in rel_path or rel_path.startswith("data/maps/"):
        return "scripts"
    if rel_path.startswith("data/text/") or rel_path.startswith("data/scripts/"):
        return "scripts"
    if "description" in rel_path.lower():
        return "descriptions"
    return "scripts"


def _is_translatable(text: str) -> bool:
    """Return True if the string has enough letters to bother translating."""
    cleaned = re.sub(r"\\[nplvfFCB.]|\\\$|\{[^}]+\}|\$", "", text)
    cleaned = re.sub(r"[^A-Za-zÀ-ÿ]", "", cleaned)
    return len(cleaned) >= 2


def _iter_source_files(root: Path) -> list[Path]:
    files: list[Path] = []
    for pattern in ("data/**/*.inc", "src/data/**/*.h", "src/data/**/*.c"):
        for path in root.glob(pattern):
            if not path.is_file():
                continue
            parts = set(path.relative_to(root).parts)
            if parts & _SKIP_DIR_PARTS:
                continue
            files.append(path)
    return sorted(files)


def extract_asm_blocks(path: Path, root: Path) -> list[SourceSpan]:
    rel = _rel(path, root)
    lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
    spans: list[SourceSpan] = []
    i = 0
    while i < len(lines):
        m = _LABEL_RE.match(lines[i])
        if not m:
            i += 1
            continue
        label = m.group(1)
        j = i + 1
        frags: list[str] = []
        while j < len(lines):
            sm = _STRING_LINE_RE.match(lines[j])
            if not sm:
                break
            frags.append(sm.group(2))
            j += 1
        if not frags:
            i += 1
            continue
        original = "".join(frags)
        # Drop trailing $ terminator used by pokeemerald string macros
        if original.endswith("$"):
            original = original[:-1]
        if _is_translatable(original):
            spans.append(
                SourceSpan(
                    entry_id=f"asm:{rel}:{label}",
                    path=rel,
                    kind="asm_block",
                    original=original,
                    category=_category_for(rel, original),
                    meta={"label": label, "label_line": i, "start": i + 1, "end": j - 1},
                )
            )
        i = j
    return spans


def extract_c_macros(path: Path, root: Path) -> list[SourceSpan]:
    rel = _rel(path, root)
    lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
    spans: list[SourceSpan] = []
    i = 0
    while i < len(lines):
        line = lines[i]

        # Multi-line _( "…" "…" );
        if _C_MULTILINE_START_RE.search(line) and '_("' not in line:
            j = i + 1
            frags: list[str] = []
            closed = False
            while j < len(lines):
                fm = _C_FRAGMENT_RE.match(lines[j])
                if not fm:
                    break
                frags.append(fm.group(1))
                if fm.group(2) == ")" or lines[j].rstrip().endswith(");") or ");" in lines[j]:
                    closed = True
                    j += 1
                    break
                j += 1
            if frags and closed:
                original = "".join(frags)
                if _is_translatable(original):
                    spans.append(
                        SourceSpan(
                            entry_id=f"cml:{rel}:{i}",
                            path=rel,
                            kind="c_multiline",
                            original=original,
                            category=_category_for(rel, original),
                            meta={"start": i, "end": j - 1, "frag_start": i + 1},
                        )
                    )
                i = j
                continue

        # Single-line _("…")
        for idx, m in enumerate(_C_STRING_RE.finditer(line)):
            original = m.group(1)
            if not _is_translatable(original):
                continue
            spans.append(
                SourceSpan(
                    entry_id=f"c:{rel}:{i}:{idx}",
                    path=rel,
                    kind="c_macro",
                    original=original,
                    category=_category_for(rel, original),
                    meta={
                        "line": i,
                        "start": m.start(1),
                        "end": m.end(1),
                        "index": idx,
                    },
                )
            )
        i += 1
    return spans


def extract_decomp_texts(source_root: Path) -> dict:
    """Scan a pokeemerald-style tree and return Meowth entries JSON."""
    root = source_root.resolve()
    if not root.is_dir():
        raise FileNotFoundError(f"Source root not found: {root}")

    spans: list[SourceSpan] = []
    for path in _iter_source_files(root):
        if path.suffix == ".inc":
            spans.extend(extract_asm_blocks(path, root))
        else:
            spans.extend(extract_c_macros(path, root))

    entries = []
    for span in spans:
        entries.append(
            {
                "id": span.entry_id,
                "original": span.original,
                "category": span.category,
                "path": span.path,
                "kind": span.kind,
                "meta": span.meta,
            }
        )

    return {
        "format": "meowth-decomp-v1",
        "source_root": str(root),
        "entries": entries,
    }


def _split_asm_string_lines(translated: str, indent: str = "\t") -> list[str]:
    """Turn a translated string (with \\n/\\p/\\l) into .string source lines."""
    text = translated
    if not text.endswith("$"):
        text = text + "$"

    # Prefer splitting after break control codes so lines stay readable
    parts: list[str] = []
    buf: list[str] = []
    i = 0
    while i < len(text):
        if text[i] == "\\" and i + 1 < len(text) and text[i + 1] in "npl":
            buf.append(text[i : i + 2])
            parts.append("".join(buf))
            buf = []
            i += 2
            continue
        buf.append(text[i])
        i += 1
    if buf:
        parts.append("".join(buf))

    # Merge tiny trailing leftover onto previous when it's only "$"
    merged: list[str] = []
    for part in parts:
        if merged and part == "$":
            merged[-1] = merged[-1] + "$"
        else:
            merged.append(part)

    if not merged:
        merged = ["$"]

    return [f'{indent}.string "{part}"' for part in merged]


def apply_asm_block(lines: list[str], meta: dict, translated: str) -> list[str]:
    start = meta["start"]
    end = meta["end"]
    indent_m = _STRING_LINE_RE.match(lines[start])
    indent = indent_m.group(1) if indent_m else "\t"
    new_lines = _split_asm_string_lines(translated, indent=indent)
    return lines[:start] + new_lines + lines[end + 1 :]


def _escape_c_fragment(text: str) -> str:
    """Escape text for a pokeemerald C string fragment in source form.

    Extracted strings keep game control codes as the two-char sequence
    ``\\`` + ``n`` (etc.). Those must appear as ``\\n`` in the ``.h`` file
    (one backslash in source → C escape → one byte, OR for game codes the
    source literally contains backslash-n which C sees as newline 0x0A —
    matching upstream pokeemerald style).
    """
    # Upstream writes control codes as \n in source (backslash + n). Keep that.
    # Only escape raw quotes; leave existing backslash-escapes intact.
    out: list[str] = []
    i = 0
    while i < len(text):
        ch = text[i]
        if ch == '"':
            out.append('\\"')
        elif ch == "\\" and i + 1 < len(text):
            out.append(ch)
            out.append(text[i + 1])
            i += 2
            continue
        elif ch == "\\":
            out.append("\\\\")
        else:
            out.append(ch)
        i += 1
    return "".join(out)


def apply_c_macro_line(line: str, translated: str, index: int) -> str:
    """Replace the index-th _(\"...\") string content on a line."""
    matches = list(_C_STRING_RE.finditer(line))
    if index >= len(matches):
        return line
    m = matches[index]
    escaped = _escape_c_fragment(translated)
    return line[: m.start(1)] + escaped + line[m.end(1) :]


def apply_c_multiline(lines: list[str], meta: dict, translated: str) -> list[str]:
    """Replace a multi-line _(\\n \"…\" \\n \"…\") block with wrapped fragments."""
    start = meta["start"]
    end = meta["end"]
    indent = "    "
    # Split on game break codes for readability, same idea as asm
    text = translated
    parts: list[str] = []
    buf: list[str] = []
    i = 0
    while i < len(text):
        if text[i] == "\\" and i + 1 < len(text) and text[i + 1] in "npl":
            buf.append(text[i : i + 2])
            parts.append("".join(buf))
            buf = []
            i += 2
            continue
        buf.append(text[i])
        i += 1
    if buf:
        parts.append("".join(buf))
    if not parts:
        parts = [""]

    new_block = [lines[start]]
    for idx, part in enumerate(parts):
        esc = _escape_c_fragment(part)
        if idx == len(parts) - 1:
            new_block.append(f'{indent}"{esc}");')
        else:
            new_block.append(f'{indent}"{esc}"')
    return lines[:start] + new_block + lines[end + 1 :]


def apply_decomp_translations(
    source_root: Path,
    translations: dict,
    output_root: Path | None = None,
) -> dict:
    """Write translated strings back into a decomp source tree.

    If output_root is None, modifies source_root in place.
    Returns a summary dict.
    """
    root = source_root.resolve()
    out = (output_root or source_root).resolve()
    if out != root:
        # Copy is the caller's responsibility; we write relative to out
        pass

    # Flatten entries from either raw extract format or post-translate format
    if "entries" in translations:
        entries = translations["entries"]
    else:
        entries = []
        for table in translations.get("tables", []):
            entries.extend(table.get("entries", []))
        entries.extend(translations.get("free_texts", []))

    by_path: dict[str, list[dict]] = {}
    for entry in entries:
        translated = entry.get("translated")
        if not translated or translated == entry.get("original"):
            continue
        path = entry.get("path")
        if not path:
            # recover path from id
            eid = entry.get("id", "")
            if eid.startswith("asm:") or eid.startswith("c:"):
                parts = eid.split(":", 2)
                if len(parts) >= 3:
                    path = parts[1]
        if not path:
            continue
        # strip quotes if present
        if translated.startswith('"') and translated.endswith('"'):
            translated = translated[1:-1]
        entry = dict(entry)
        entry["translated"] = translated
        by_path.setdefault(path, []).append(entry)

    files_changed = 0
    strings_applied = 0

    for rel, path_entries in sorted(by_path.items()):
        src_path = root / rel
        dst_path = out / rel
        if not src_path.is_file():
            continue
        lines = src_path.read_text(encoding="utf-8", errors="replace").splitlines()

        def _kind(entry: dict) -> str:
            if entry.get("kind"):
                return entry["kind"]
            eid = str(entry.get("id", ""))
            if eid.startswith("asm:"):
                return "asm_block"
            if eid.startswith("cml:"):
                return "c_multiline"
            if eid.startswith("c:"):
                return "c_macro"
            return ""

        # Apply block-level edits from bottom to top so line indices stay valid
        block_entries = [
            e for e in path_entries if _kind(e) in ("asm_block", "c_multiline")
        ]
        block_entries.sort(key=lambda e: e.get("meta", {}).get("start", 0), reverse=True)
        for entry in block_entries:
            meta = entry.get("meta") or {}
            if "start" not in meta:
                continue
            if _kind(entry) == "asm_block":
                lines = apply_asm_block(lines, meta, entry["translated"])
            else:
                lines = apply_c_multiline(lines, meta, entry["translated"])
            strings_applied += 1

        # Single-line C macros: group by line, apply highest index first
        c_entries = [e for e in path_entries if _kind(e) == "c_macro"]
        c_by_line: dict[int, list[dict]] = {}
        for entry in c_entries:
            meta = entry.get("meta") or {}
            if "line" not in meta:
                continue
            c_by_line.setdefault(meta["line"], []).append(entry)
        for line_idx, group in c_by_line.items():
            group.sort(key=lambda e: e.get("meta", {}).get("index", 0), reverse=True)
            line = lines[line_idx]
            for entry in group:
                line = apply_c_macro_line(line, entry["translated"], entry["meta"]["index"])
                strings_applied += 1
            lines[line_idx] = line

        dst_path.parent.mkdir(parents=True, exist_ok=True)
        dst_path.write_text("\n".join(lines) + "\n", encoding="utf-8")
        files_changed += 1

    return {
        "files_changed": files_changed,
        "strings_applied": strings_applied,
        "output_root": str(out),
    }


def write_extract(source_root: Path, output_json: Path) -> dict:
    data = extract_decomp_texts(source_root)
    output_json.parent.mkdir(parents=True, exist_ok=True)
    output_json.write_text(json.dumps(data, ensure_ascii=False, indent=2), encoding="utf-8")
    return data
