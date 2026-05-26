# CNoBS

> **C, No BS.** That's it. That's the name.

[![compile-check](https://github.com/ajithakdev/learn-c/actions/workflows/compile-check.yml/badge.svg)](https://github.com/ajithakdev/learn-c/actions/workflows/compile-check.yml)
[![test](https://github.com/ajithakdev/learn-c/actions/workflows/test.yml/badge.svg)](https://github.com/ajithakdev/learn-c/actions/workflows/test.yml)

**C without the bullshit.** No 400-page books. No "hello world" for 3 chapters. No theory dumps. Code that runs, breaks, and teaches you why — in 5 minutes or it's a bad lesson.

> You have 20 minutes between classes. You learn by breaking things. You quit if the lesson doesn't pay off in 5. This repo is for you.

---

## Why C in 2026

Every language you use is written in C, runs on a runtime written in C, or borrows C's mental model (pointers, memory, structs). Learn C once, read the source of anything. It's also the fastest path to understanding *why* your Python is slow.

Deep dive: [docs/WHY_C_STILL_MATTERS.md](docs/WHY_C_STILL_MATTERS.md)

---

## Learning path

```
   START                  HARD PART                  SHIP
     |                        |                        |
     v                        v                        v
 00-basics    01-functions    02-pointers   03-memory   04-strings
   (3)            (2)             (6)          (2)         (3)
                                  |
                                  |   05-structs  06-file-io  07-advanced
                                  v       (2)         (2)         (3)
                              mnemonics
                                  |
                                  v
                           challenges/         tier 1 (foundational)
                                  |            tier 2 (pointers)
                                  v            tier 3 (integration)
                            practice/          easy / medium / hard
                                  |
                                  v
                            projects/
                              guess (beginner)
                              phonebook (intermediate)
                              capstone (expression evaluator)
```

23 lessons. ~10-15 min each. ~8 weeks at 4-5 hrs/week.

---

## Quick start

```bash
git clone https://github.com/ajithakdev/learn-c CNoBS
cd CNoBS
gcc lessons/00-basics/01-types-and-output.c && ./a.out
```

Full setup (Windows / macOS / Linux): [ONBOARDING.md](ONBOARDING.md).

---

## How a lesson works

1. **Output first.** Look at expected stdout. Guess what the code does.
2. **Code reveal.** Read ≤30 lines.
3. **Why it works.** One paragraph. No theory dump.
4. **ASCII diagram.** Memory, stack, or pointer.
5. **BREAK IT.** Change one line. Predict. Run. See.

You're debugging from minute one.

---

## Repo map

```
CNoBS/
├── README.md                   <- you are here
├── ONBOARDING.md               <- compiler setup + first run
├── CONTRIBUTING.md             <- PR rules
├── Makefile                    <- make compile-check / make test
├── .github/workflows/          <- CI: every PR compiles + diffs output
├── lessons/                    <- atomic, ≤30 lines each
│   ├── 00-basics/              types, operators, control flow
│   ├── 01-functions/           defs, scope, stack
│   ├── 02-pointers/            6 lessons, ASCII memory every step
│   ├── 03-memory/              stack vs heap, malloc/free
│   ├── 04-strings/             char arrays, string.h, strcpy dangers
│   ├── 05-structs/             your own types
│   ├── 06-file-io/             fopen/fgets/fprintf
│   └── 07-advanced/            typedef, unions, bit ops
├── challenges/                 <- tiered break-it labs
│   ├── tier-1-foundational/
│   ├── tier-2-pointers/
│   ├── tier-3-integration/
│   └── solutions/              (hidden via .gitignore)
├── practice/                   <- bonus problems with skeletons
│   ├── 01-easy-warmup/
│   ├── 02-medium/
│   └── 03-hard/
├── patterns/                   <- real copy-paste snippets
├── mnemonics/                  <- one-page memory aids (ASCII)
├── projects/
│   ├── guess/                  beginner
│   ├── phonebook/              intermediate
│   └── capstone/               expression evaluator
├── tests/                      <- expected_outputs + test_lessons.sh
├── scripts/                    <- compile_check.sh
└── docs/                       <- optional deeper reads
```

---

## Running tests locally

```bash
make compile-check   # compile every .c, fail on warning
make test            # run lessons, diff stdout vs golden files
```

CI does the same on every push and PR.

---

## Anti-hype promise

- No "C is hard" gaslighting. K&R is 272 pages. Your JS framework docs are longer.
- No theory before code. Ever.
- No lesson > 30 lines. If longer, it's a pattern or project.
- Every `.c` file compiles. If one doesn't, open an issue. CI would have caught it.

---

## Contributing

PRs welcome. Rules in [CONTRIBUTING.md](CONTRIBUTING.md). Hard rule: don't break the build.

---

## Author

Built by **[ajithakdev](https://github.com/ajithakdev)**.
Contact: ajithkumarks2579@gmail.com · cseajithak@gmail.com

Issues + PRs welcome. If a `.c` file doesn't compile, that's a bug — file it.
