#!/usr/bin/env bash
set -u

if [[ $# -ne 1 ]]; then
  echo "usage: $0 FILE" >&2
  exit 2
fi

file="$1"
if [[ ! -f "$file" ]]; then
  echo "clipboard source not found: $file" >&2
  exit 1
fi

if [[ -n "${WSL_DISTRO_NAME:-}" ]] && command -v clip.exe >/dev/null 2>&1; then
  if clip.exe < "$file"; then
    echo "copied to clipboard: $file"
    exit 0
  fi
fi

if [[ -n "${WAYLAND_DISPLAY:-}" ]] && command -v wl-copy >/dev/null 2>&1; then
  if wl-copy < "$file"; then
    echo "copied to clipboard: $file"
    exit 0
  fi
fi

if command -v pbcopy >/dev/null 2>&1; then
  if pbcopy < "$file"; then
    echo "copied to clipboard: $file"
    exit 0
  fi
fi

if [[ -n "${DISPLAY:-}" ]] && command -v xclip >/dev/null 2>&1; then
  if xclip -selection clipboard < "$file"; then
    echo "copied to clipboard: $file"
    exit 0
  fi
fi

if [[ -n "${DISPLAY:-}" ]] && command -v xsel >/dev/null 2>&1; then
  if xsel --clipboard --input < "$file"; then
    echo "copied to clipboard: $file"
    exit 0
  fi
fi

echo "clipboard copy failed: install wl-clipboard, xclip, or xsel (macOS uses pbcopy)" >&2
exit 1
