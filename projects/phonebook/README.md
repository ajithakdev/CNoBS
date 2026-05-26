# Phonebook

Intermediate project. Add contacts, list, search. Persists to `book.txt` between runs.

```bash
gcc phonebook.c -o phonebook
./phonebook
```

Covers: structs, fixed-size arrays, file I/O (load + save), case-insensitive substring search, menu loop.

## Test

```bash
gcc phonebook_test.c -o phonebook_test
./phonebook_test
```

`phonebook_test.c` tests the search helpers (case-insensitive prefix + contains) directly.

## Modify ideas

- Add a `delete` option (shift array down, save).
- Sort alphabetically before printing.
- Support names with spaces (use `fgets` instead of `scanf %s`).
- Swap linear search for a hash table — see `practice/02-medium/simple-hash.c`.
