# CNoBS

**C without the BS.** No 400-page books. No "hello world" for 3 chapters. Just code that runs, breaks, and teaches you why.

> You have 20 minutes between classes. You learn by breaking things. You quit if the lesson doesn't pay off in 5. This repo is for you.

---

## Why C in 2026

Every language you use is written in C, runs on a runtime written in C, or borrows C's mental model (pointers, memory, structs). Learn C once, read the source of anything. It's also the fastest path to understanding *why* your Python is slow.

---

## Learning Path

```
                    START HERE
                        |
              [ lessons/ ] 10-15 min each
                        |
        +---------------+---------------+
        |               |               |
     basics         pointers         structs
   (types, if,    (the hard part,    (real data)
    loops, fns)    5 lessons w/
                   ASCII memory)
        |               |               |
        +-------+-------+
                |
        [ challenges/ ]
        break-it labs, copy-paste,
        change ONE thing, see Y
                |
        [ patterns/ ]
        snippets people actually
        write (sort, search, concat)
                |
        [ projects/ ]
        1. guess-the-number  (beginner)
        2. phonebook         (intermediate)
                |
              SHIP
```

---

## Quick Start (under 2 minutes)

```bash
git clone <this-repo>
cd CNoBS/lessons
gcc 01-output-first.c && ./a.out
```

You need:
- A C compiler. **gcc** (Linux/Mac/WSL) or **clang** (Mac). Windows: install MSYS2 or use WSL.
- A terminal. That's it.

Check it works:

```bash
gcc --version
```

If you see a version number, you're done with setup. No IDE. No `package.json`. No `node_modules`. C is a 50-year-old language that still runs on a fresh laptop with zero config.

---

## How Lessons Work (Reverse Teaching)

Every lesson follows the same pattern:

1. **Output first.** Look at what it prints. Guess what the code does.
2. **Code reveal.** Read 20-30 lines max.
3. **Why it works.** One paragraph. No theory dump.
4. **ASCII diagram.** See the memory, stack, or pointer.
5. **Break it.** Change one line. Predict the new output. Run it.

You're not reading. You're debugging from minute one.

---

## What You'll Know By The End

You'll write C that allocates memory, manages pointers without segfaulting (most of the time), reads and writes files, builds small data structures (linked lists, hash tables — the easy way), and reads other people's C code without your eyes glazing over. You won't be a kernel hacker. You will be able to debug a segfault, understand why `strcpy` is dangerous, and follow along when someone explains how malloc works.

Honest scope: **beginner → comfortable intermediate**. Not "systems programmer." Not yet.

---

## Repo Map

```
CNoBS/
├── README.md            <- you are here
├── lessons/             <- atomic, ~10 min each
│   ├── 01-output-first.c
│   ├── 02-pointers-visual.c
│   ├── 03-arrays-memory.c
│   └── 04-structs.c
├── challenges/          <- break-it labs
│   ├── 01-fix-the-loop.c
│   └── 02-pointer-puzzle.c
├── patterns/            <- real snippets
│   └── string-search.c
└── projects/
    ├── guess/           <- beginner
    │   └── guess.c
    └── phonebook/       <- intermediate
        └── phonebook.c
```

---

## Anti-Hype Promise

- No "C is hard" gaslighting. It's small. K&R is 272 pages. Your JavaScript framework docs are longer.
- No theory before code. Ever.
- No file longer than 30 lines in lessons. If it's longer, it's a pattern.
- Every `.c` file compiles. If one doesn't, open an issue.

Now go run `lessons/01-output-first.c`.

---

## Author

Built by **[ajithakdev](https://github.com/ajithakdev)**.
Contact: ajithkumarks2579@gmail.com · cseajithak@gmail.com

Issues + PRs welcome. If a `.c` file doesn't compile, that's a bug — file it.
