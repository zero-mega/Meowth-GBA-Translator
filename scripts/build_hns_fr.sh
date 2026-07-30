#!/usr/bin/env bash
# Build Heart & Soul with the committed French overlay (make modern).
# Requires: arm-none-eabi-gcc, libpng-dev, make, git
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
BUILD_DIR="${BUILD_DIR:-$ROOT/work/pokemonHnS_build}"
HNS_REPO="${HNS_REPO:-https://github.com/PokemonHnS-Development/pokemonHnS.git}"
HNS_REF="${HNS_REF:-main}"

if [[ ! -d "$BUILD_DIR/.git" ]]; then
  git clone --depth 1 --branch "$HNS_REF" "$HNS_REPO" "$BUILD_DIR"
else
  git -C "$BUILD_DIR" fetch --depth 1 origin "$HNS_REF"
  git -C "$BUILD_DIR" checkout -f FETCH_HEAD
fi

"$ROOT/scripts/apply_hns_fr_overlay.sh" "$BUILD_DIR"
# Ensure make sees overlay as newer than any cached objects
find "$ROOT/translations/pokemonHnS_fr" -type f -exec touch {} +
find "$ROOT/translations/pokemonHnS_fr" -type f -print0 | while IFS= read -r -d '' f; do
  rel="${f#$ROOT/translations/pokemonHnS_fr/}"
  touch "$BUILD_DIR/$rel"
done

unset DEVKITARM || true
make -C "$BUILD_DIR" modern -j"$(nproc)"
ls -lh "$BUILD_DIR/pokemonHnS.gba"
echo "Built: $BUILD_DIR/pokemonHnS.gba"
