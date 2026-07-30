#!/usr/bin/env bash
# Apply committed French overlay onto a Heart & Soul decomp checkout.
# Usage: ./scripts/apply_hns_fr_overlay.sh /path/to/pokemonHnS
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
DEST="${1:?Usage: $0 /path/to/pokemonHnS}"
OVERLAY="$ROOT/translations/pokemonHnS_fr"
test -d "$OVERLAY"
test -d "$DEST"

# Prefer rsync; fall back to find+cp
if command -v rsync >/dev/null 2>&1; then
  rsync -a "$OVERLAY"/ "$DEST"/
else
  (
    cd "$OVERLAY"
    find . -type f -print0 | while IFS= read -r -d '' f; do
      mkdir -p "$DEST/$(dirname "$f")"
      cp -p "$f" "$DEST/$f"
    done
  )
fi
echo "Applied French overlay → $DEST"
