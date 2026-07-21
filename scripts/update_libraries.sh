#!/usr/bin/env bash
set -euo pipefail

usage() {
  cat <<'USAGE'
usage: scripts/update_libraries.sh [DIR]

Update installed Git libraries with a fast-forward-only pull.
If DIR is omitted, every Git repository directly under lib/ is updated.
DIR may be either a library name (for example cp_library) or a path under lib/.
USAGE
}

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
library_root="$repo_root/lib"

update_library() {
  local dir="$1"
  local display branch upstream

  display="${dir#"$repo_root"/}"

  if [[ ! -e "$dir/.git" ]] ||
    ! git -C "$dir" rev-parse --is-inside-work-tree >/dev/null 2>&1; then
    echo "not a Git repository: $display" >&2
    return 1
  fi

  if [[ -n "$(git -C "$dir" status --porcelain)" ]]; then
    echo "library has local changes; commit or stash them first: $display" >&2
    return 1
  fi

  branch="$(git -C "$dir" branch --show-current)"
  if [[ -z "$branch" ]]; then
    echo "library is in detached HEAD state: $display" >&2
    return 1
  fi

  if ! upstream="$(git -C "$dir" rev-parse --abbrev-ref --symbolic-full-name '@{upstream}' 2>/dev/null)"; then
    echo "branch has no upstream: $display ($branch)" >&2
    return 1
  fi

  echo "updating: $display ($branch <- $upstream)"
  git -C "$dir" pull --ff-only
}

if [[ $# -gt 1 ]]; then
  usage >&2
  exit 1
fi

if [[ "${1:-}" == "-h" || "${1:-}" == "--help" ]]; then
  usage
  exit 0
fi

if [[ $# -eq 1 ]]; then
  requested="$1"
  if [[ "$requested" == /* ]]; then
    target="$requested"
  elif [[ "$requested" == lib/* ]]; then
    target="$repo_root/$requested"
  else
    target="$library_root/$requested"
  fi

  target="$(realpath -m "$target")"
  case "$target" in
    "$library_root"/*) ;;
    *)
      echo "library must be located under lib/: $requested" >&2
      exit 1
      ;;
  esac

  update_library "$target"
  exit 0
fi

libraries=()
for dir in "$library_root"/*; do
  [[ -d "$dir" ]] || continue
  if [[ -e "$dir/.git" ]] &&
    git -C "$dir" rev-parse --is-inside-work-tree >/dev/null 2>&1; then
    libraries+=("$dir")
  fi
done

if [[ ${#libraries[@]} -eq 0 ]]; then
  echo "no installed Git libraries found under lib/" >&2
  exit 1
fi

status=0
for dir in "${libraries[@]}"; do
  if ! update_library "$dir"; then
    status=1
  fi
done
exit "$status"
