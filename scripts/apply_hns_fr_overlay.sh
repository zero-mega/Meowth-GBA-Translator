#!/usr/bin/env bash
# Apply committed French overlay onto a Heart & Soul decomp checkout.
# Usage: ./scripts/apply_hns_fr_overlay.sh /path/to/pokemonHnS
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
DEST="${1:?Usage: $0 /path/to/pokemonHnS}"
OVERLAY="$ROOT/translations/pokemonHnS_fr"
test -d "$OVERLAY"
rsync -a "$OVERLAY"/ "$DEST"/
echo "Applied French overlay → $DEST"
