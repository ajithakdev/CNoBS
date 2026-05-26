#!/usr/bin/env bash
# Compile each lesson, run it, diff stdout against tests/expected_outputs/.
# Skips lessons without a matching expected file (non-deterministic ones).

set -u
CC="${CC:-gcc}"
CFLAGS="${CFLAGS:--Wall -Wextra -std=c11}"
BUILD="tests/.build"
EXPECTED="tests/expected_outputs"
mkdir -p "$BUILD"

pass=0
fail=0
skip=0
failed_names=()

shopt -s nullglob
for src in lessons/*/*.c; do
    rel="${src#lessons/}"
    # turn lessons/00-basics/01-foo.c -> 00-basics_01-foo
    key="${rel%.c}"
    key="${key//\//_}"
    expected="$EXPECTED/${key}.txt"

    if [ ! -f "$expected" ]; then
        skip=$((skip + 1))
        continue
    fi

    bin="$BUILD/${key}.out"
    if ! $CC $CFLAGS "$src" -o "$bin" 2>"$BUILD/${key}.cerr"; then
        fail=$((fail + 1))
        failed_names+=("$key (compile)")
        echo "FAIL compile: $src"
        sed 's/^/    /' "$BUILD/${key}.cerr"
        continue
    fi

    actual="$BUILD/${key}.out.txt"
    "$bin" >"$actual" 2>&1 || true

    if diff -u "$expected" "$actual" >"$BUILD/${key}.diff"; then
        pass=$((pass + 1))
    else
        fail=$((fail + 1))
        failed_names+=("$key (output)")
        echo "FAIL output: $src"
        sed 's/^/    /' "$BUILD/${key}.diff"
    fi
done

echo ""
echo "===================="
echo " passed:  $pass"
echo " failed:  $fail"
echo " skipped: $skip (no expected_outputs file)"
echo "===================="

if [ "$fail" -ne 0 ]; then
    echo "Failed: ${failed_names[*]}"
    exit 1
fi
