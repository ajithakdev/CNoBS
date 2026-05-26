#!/usr/bin/env bash
# Compile every .c file in the repo. Fail on any error.
# Does NOT run binaries.

set -u
CC="${CC:-gcc}"
CFLAGS="${CFLAGS:--Wall -Wextra -std=c11}"

fail=0
pass=0
tmpdir="$(mktemp -d)"
trap 'rm -rf "$tmpdir"' EXIT

while IFS= read -r -d '' src; do
    out="$tmpdir/$(basename "$src" .c).out"
    if $CC $CFLAGS "$src" -o "$out" 2>"$tmpdir/err"; then
        pass=$((pass + 1))
    else
        fail=$((fail + 1))
        echo "FAIL: $src"
        sed 's/^/    /' "$tmpdir/err"
    fi
done < <(find lessons patterns practice projects challenges -name "*.c" -print0)

echo ""
echo "compile-check: $pass passed, $fail failed."
[ "$fail" -eq 0 ]
