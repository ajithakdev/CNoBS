# Capstone — Expression Evaluator

Final project. Parse + evaluate integer expressions with +, -, *, /, parentheses, unary minus.

```
3 + 5 * (2 - 8) / 2   ->  -12
```

## Why

Combines everything:

- **strings** — walk the input
- **pointers** — cursor over chars, parser state
- **recursion** — grammar is recursive (expr -> term -> factor -> expr)
- **structs** — parser state
- **file I/O** — `--file` mode reads expressions line by line
- **error handling** — bad input returns non-zero, no crash

Recursive-descent parsers exist in every interpreter, compiler, and config loader. Once you've written one, you've seen the shape.

## Run

```bash
gcc capstone.c -o capstone
./capstone "3 + 5 * 2"
./capstone --file exprs.txt
```

## Test

```bash
gcc capstone_test.c -o capstone_test
./capstone_test
```

Expected: `capstone_test: 10 passed, 0 failed.`

## Grammar

```
expr   = term   (('+' | '-') term)*
term   = factor (('*' | '/') factor)*
factor = number | '(' expr ')' | '-' factor
```

Left-associative. Standard precedence: `*` and `/` bind tighter than `+` and `-`.

## Extend it

- Add `^` (power). Right-associative — careful.
- Add variables: `x = 5; x + 3`.
- Switch to floats.
- Add functions: `sqrt(2)`, `max(a, b)`.
- Compile to a stack-based VM instead of direct eval.
