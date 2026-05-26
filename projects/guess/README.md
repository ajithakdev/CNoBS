# Guess The Number

Beginner project. Random secret 1-100. You guess. Higher/lower hints.

```bash
gcc guess.c -o guess
./guess
```

Covers: `rand` + `srand`, `scanf`, while loop, simple branching.

## Test

```bash
gcc guess_test.c -o guess_test
./guess_test
```

`guess_test.c` smoke-tests the comparison logic without needing stdin or randomness.

## Modify ideas

- Make range 1-1000.
- Limit to 7 tries, give up with `the number was %d`.
- Track best score across runs in a file (see phonebook for file I/O).
