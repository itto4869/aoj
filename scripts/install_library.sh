#!/usr/bin/env bash
set -euo pipefail

if [[ $# -lt 1 || $# -gt 3 ]]; then
  echo "usage: $0 URL [DIR] [BRANCH]" >&2
  echo "       $0 URL --branch BRANCH" >&2
  exit 1
fi

url="$1"
dir="${2:-}"
branch="${3:-}"

if [[ "$dir" == "-b" || "$dir" == "--branch" ]]; then
  if [[ -z "$branch" ]]; then
    echo "branch name is required" >&2
    exit 1
  fi
  dir=""
elif [[ -z "$branch" && "$dir" == *:* ]]; then
  # Keep scp-like Git URLs such as git@github.com:USER/REPO.git from being
  # confused with a directory/branch pair by future argument extensions.
  :
fi

if [[ -z "$dir" ]]; then
  repo="${url%.git}"
  repo="${repo##*/}"
  dir="lib/$repo"
fi

mkdir -p "$(dirname "$dir")"

if [[ -d "$dir/.git" ]]; then
  if [[ -n "$branch" ]]; then
    git -C "$dir" fetch origin "$branch"
    git -C "$dir" checkout "$branch"
  fi
  git -C "$dir" pull --ff-only
elif [[ -e "$dir" ]]; then
  echo "target exists and is not a git repository: $dir" >&2
  exit 1
else
  if [[ -n "$branch" ]]; then
    git clone --depth 1 --branch "$branch" "$url" "$dir"
  else
    git clone --depth 1 "$url" "$dir"
  fi
fi

echo "library ready: $dir"
