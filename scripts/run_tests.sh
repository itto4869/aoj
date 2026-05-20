#!/usr/bin/env bash
set -euo pipefail

if [[ $# -ne 4 ]]; then
  echo "usage: $0 BIN NAME INPUT EXPECTED" >&2
  exit 1
fi

bin="$1"
name="$2"
input="$3"
expected="$4"

run_case() {
  local case_name="$1"
  local in_file="$2"
  local out_file="$3"
  local actual="build/${name}.${case_name}.actual"
  local normalized_expected="build/${name}.${case_name}.expected.normalized"
  local normalized_actual="build/${name}.${case_name}.actual.normalized"

  if [[ ! -f "$out_file" ]]; then
    echo "expected file not found: $out_file" >&2
    return 1
  fi

  if [[ -f "$in_file" ]]; then
    "$bin" < "$in_file" > "$actual"
  else
    "$bin" > "$actual"
  fi

  strip_one_final_lf "$out_file" "$normalized_expected"
  strip_one_final_lf "$actual" "$normalized_actual"

  diff -u --label "$out_file" --label "$actual" "$normalized_expected" "$normalized_actual"
  echo "ok: $case_name"
}

strip_one_final_lf() {
  local src="$1"
  local dst="$2"
  local last_byte

  last_byte="$(tail -c 1 "$src" 2>/dev/null | od -An -t x1 | tr -d '[:space:]')"
  if [[ "$last_byte" == "0a" ]]; then
    head -c -1 "$src" > "$dst"
  else
    cp "$src" "$dst"
  fi
}

case_dir="samples/$name"
found=0

if [[ -f "$expected" ]]; then
  run_case "$name" "$input" "$expected"
  found=1
fi

if [[ -d "$case_dir" ]]; then
  while IFS= read -r -d '' in_file; do
    base="$(basename "$in_file" .in)"
    run_case "$base" "$in_file" "$case_dir/$base.out"
    found=1
  done < <(find "$case_dir" -maxdepth 1 -type f -name '*.in' -print0 | sort -z)
fi

if [[ "$found" -eq 0 ]]; then
  echo "no test cases found: $expected or $case_dir/*.in" >&2
  exit 1
fi
