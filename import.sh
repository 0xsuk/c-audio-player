#!/bin/sh

if ! command -v ffmpeg >/dev/null 2>&1; then
  echo "Error: ffmpeg is not installed." >&2
  exit 1
fi

FILE="$1"
RATE="44100"

exec ffmpeg -v 0 -i "$FILE" -f s16le -ar "$RATE" - # send output to stdin
