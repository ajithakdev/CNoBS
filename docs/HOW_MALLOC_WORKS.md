# How malloc Actually Works

Optional reading. Skip if you just want to write C.

---

## The short version

`malloc(n)` asks the C runtime for `n` bytes from a region called the **heap**. The runtime tracks a free list of available chunks. `free(p)` returns the chunk to that list.

The OS hands the C runtime large pages of memory via `brk` / `sbrk` (extend program break) or `mmap` (anonymous mapping). The runtime carves those pages into the small chunks you ask for.

---

## What the runtime does

1. Round your request up to an alignment boundary (usually 8 or 16 bytes).
2. Look in the free list for a chunk big enough.
3. If found, split it and return a pointer to the payload.
4. If not, ask the OS for more memory.
5. Store metadata in the bytes BEFORE the pointer you got back (size, prev/next free pointers).

This is why writing one byte BEFORE your pointer corrupts the heap. You smashed the metadata.

---

## Implementations

- **ptmalloc2** — what glibc uses. Per-thread arenas, multiple bins.
- **jemalloc** — Facebook. Better under contention.
- **tcmalloc** — Google. Thread-local caches.
- **mimalloc** — Microsoft. Modern, fast.

Same API. Different perf. Same bugs bite all of them.

---

## Why free() doesn't shrink your process

`free()` returns the chunk to the runtime, not to the OS. Your process's resident memory stays high until you exit (or call `malloc_trim`, glibc-only). This surprises people watching `top`.

---

## See also

- [mnemonics/MALLOC_RULES.txt](../mnemonics/MALLOC_RULES.txt)
- [lessons/03-memory/02-malloc-free.c](../lessons/03-memory/02-malloc-free.c)
- `man 3 malloc`
- Doug Lea's allocator paper (the basis for ptmalloc)
