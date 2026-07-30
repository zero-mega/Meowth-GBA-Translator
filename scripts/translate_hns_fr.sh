#!/usr/bin/env bash
# Translate Pokémon Heart & Soul (decomp source) to French via Meowth.
#
# Heart & Soul is a pokeemerald decomp (https://github.com/PokemonHnS-Development/pokemonHnS).
# Meowth extracts .string / _() text from the open-source tree, translates with an LLM
# (official FR names come from the PokeAPI glossary), then writes a French source tree.
#
# Requires:
#   - An LLM API key, e.g.:  export DEEPSEEK_API_KEY=sk-...
#   - Network access to clone the HnS repo
#
# Usage (from Meowth repo root):
#   ./scripts/translate_hns_fr.sh
#   HNS_REF=Release-v1.2.1 ./scripts/translate_hns_fr.sh
#
# Note: Building a playable .gba still needs a legally obtained Emerald ROM + pret toolchain
# (make modern), or patch the official HnS UPS onto Emerald and use `meowth full --target fr`.
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"
export PATH="${HOME}/.local/bin:${PATH}"

HNS_REPO="${HNS_REPO:-https://github.com/PokemonHnS-Development/pokemonHnS.git}"
HNS_REF="${HNS_REF:-main}"
HNS_DIR="${HNS_DIR:-work/pokemonHnS}"
OUT_DIR="${OUT_DIR:-outputs/pokemonHnS_fr}"
WORK_DIR="${WORK_DIR:-work/hns_fr}"
PROVIDER="${PROVIDER:-deepseek}"
TARGET="${TARGET:-fr}"

if [[ -z "${DEEPSEEK_API_KEY:-}" && -z "${OPENAI_API_KEY:-}" && -z "${GOOGLE_API_KEY:-}" \
   && -z "${ANTHROPIC_API_KEY:-}" && -z "${OPENROUTER_API_KEY:-}" \
   && -z "${GROQ_API_KEY:-}" && -z "${MISTRAL_API_KEY:-}" ]]; then
  echo "error: set an LLM API key first (e.g. export DEEPSEEK_API_KEY=sk-...)" >&2
  echo "Without a key, only glossary-backed names (Pokémon/moves/…) can be localized." >&2
  exit 1
fi

mkdir -p "$(dirname "$HNS_DIR")" "$WORK_DIR"

if [[ ! -d "$HNS_DIR/.git" ]]; then
  echo "Cloning Heart & Soul ($HNS_REF, sparse text sources)…"
  git clone --depth 1 --filter=blob:none --sparse --branch "$HNS_REF" "$HNS_REPO" "$HNS_DIR"
  git -C "$HNS_DIR" sparse-checkout set data/text data/maps data/scripts src/data
else
  echo "Using existing clone at $HNS_DIR"
fi

if ! command -v meowth >/dev/null 2>&1; then
  pip install -e "$ROOT" >/dev/null
fi

echo "Running Meowth decomp-full → $TARGET…"
meowth decomp-full "$HNS_DIR" \
  --output-root "$OUT_DIR" \
  --work-dir "$WORK_DIR" \
  --source en \
  --target "$TARGET" \
  --provider "$PROVIDER"

echo
echo "French sources written to: $OUT_DIR"
echo "Next: build with pret pokeemerald tooling (make modern) using your Emerald assets."
