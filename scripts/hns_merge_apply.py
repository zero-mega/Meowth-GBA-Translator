#!/usr/bin/env python3
"""Merge translated HnS chunks and apply into a French source tree."""

from __future__ import annotations

import json
import shutil
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "src"))

from meowth.decomp import apply_decomp_translations  # noqa: E402


def main() -> None:
    work = ROOT / "work" / "hns_fr"
    hns = ROOT / "work" / "pokemonHnS"
    out = ROOT / "outputs" / "pokemonHnS_fr"
    chunk_dir = work / "chunks"

    manifest = json.loads((work / "chunks_manifest.json").read_text(encoding="utf-8"))
    pre = json.loads((work / "pretranslated.json").read_text(encoding="utf-8"))
    extract = json.loads((work / "decomp_texts.json").read_text(encoding="utf-8"))

    by_id = {e["id"]: dict(e) for e in extract["entries"]}
    for eid, tr in pre.items():
        if eid in by_id:
            by_id[eid]["translated"] = tr

    done = 0
    missing = []
    for name in manifest["chunks"]:
        path = chunk_dir / name
        data = json.loads(path.read_text(encoding="utf-8"))
        for item in data["items"]:
            tr = item.get("translated")
            if not tr:
                missing.append((name, item["original"][:60]))
                continue
            done += 1
            for eid in item["ids"]:
                if eid in by_id:
                    by_id[eid]["translated"] = tr

    total_unique = manifest["total_unique"]
    print(f"merged unique translations: {done}/{total_unique}")
    print(f"missing: {len(missing)}")
    if missing[:5]:
        print("  e.g.", missing[:5])

    flat = list(by_id.values())
    changed = sum(
        1
        for e in flat
        if e.get("translated") and e["translated"] != e.get("original")
    )
    print(f"entries with translation ≠ original: {changed}/{len(flat)}")

    out_json = work / "decomp_texts_translated.json"
    out_json.write_text(
        json.dumps({"format": "meowth-decomp-v1", "entries": flat}, ensure_ascii=False, indent=2),
        encoding="utf-8",
    )

    if out.exists():
        shutil.rmtree(out)
    print(f"copying {hns} → {out}")
    shutil.copytree(hns, out, ignore=shutil.ignore_patterns(".git"))
    summary = apply_decomp_translations(out, {"entries": flat}, out)
    print(summary)

    if missing:
        sys.exit(2)


if __name__ == "__main__":
    main()
