# Contributing to CNoBS

Welcome. Two rules: don't break the build, follow the template.

---

## Hard rules

1. Every `.c` file MUST compile cleanly with `gcc -Wall -Wextra -std=c11`.
2. Every lesson MUST pass `make test`.
3. If you add a deterministic lesson, you MUST add a matching golden file in [tests/expected_outputs/](tests/expected_outputs/).
4. No PR merges if CI fails. Fix it locally first.

---

## Lesson template

```c
/*
 * Lesson: [topic] | Time: ~N min | Difficulty: easy|medium
 * Why this matters: [one sentence, no fluff]
 *
 * Run: gcc file.c && ./a.out
 *
 * EXPECTED OUTPUT:
 * ------------------------------------------
 *   [exact stdout]
 * ------------------------------------------
 *
 * MEMORY DIAGRAM (if pointers / memory relevant)
 */

#include <stdio.h>
/* code: 30 lines MAX */

/*
 * Why it works: [one paragraph]
 *
 * BREAK IT:
 *   1. [change X, predict, run]
 *   2. ...
 */
```

Hard cap: 30 lines of actual code per lesson. If you need more, it belongs in `patterns/` or `projects/`.

---

## Workflow

1. Fork.
2. Branch: `git checkout -b lesson/my-topic`.
3. Write the lesson + the expected_outputs file.
4. Run locally:
   ```bash
   make compile-check
   make test
   ```
5. Both green? Push. Open PR against `main`.
6. CI runs the same checks. Green = mergeable.

---

## Tone

- Punchy. Sarcastic when honest. Never condescending.
- Comments explain WHY, not WHAT.
- No "learning journey" language. No emojis (unless asked).
- Errors fail LOUDLY.

---

## Bug reports

A `.c` file doesn't compile? That's a bug. Open an issue with:
- OS + compiler version
- Exact command run
- Exact error output

Maintainer: [ajithakdev](https://github.com/ajithakdev) · ajithkumarks2579@gmail.com / cseajithak@gmail.com
