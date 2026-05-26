# Patterns

Real snippets people actually write. Copy. Adapt. Ship.

| File | When to use |
|------|-------------|
| [string-search.c](string-search.c) | Find a substring (no `strstr`) — strings lesson follow-up |
| [array-sort.c](array-sort.c) | Sort small array — when `qsort` overkill |
| [file-read-lines.c](file-read-lines.c) | Count/process lines in a text file |
| [malloc-cleanup.c](malloc-cleanup.c) | Multiple allocs + clean error path (`goto cleanup`) |

Production code: prefer `strstr`, `qsort`, and your platform's safer string fns. These show the mechanics.
