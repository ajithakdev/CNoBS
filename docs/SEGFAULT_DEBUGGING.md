# Debugging a Segfault

Your program crashed with `Segmentation fault`. That's the OS killing you for touching memory you don't own. Here's the playbook.

---

## Step 1 — Compile with sanitizers

```bash
gcc -g -fsanitize=address,undefined -fno-omit-frame-pointer file.c && ./a.out
```

AddressSanitizer (ASan) catches:
- Out-of-bounds reads/writes
- Use-after-free
- Double-free
- Memory leaks (with `ASAN_OPTIONS=detect_leaks=1`)

UndefinedBehaviorSanitizer (UBSan) catches:
- Signed overflow
- Misaligned loads
- Null pointer arithmetic

If ASan flags it, the report points to the exact line.

---

## Step 2 — Run under gdb

```bash
gcc -g file.c
gdb ./a.out
(gdb) run
(gdb) bt          # backtrace when it crashes
(gdb) frame 0     # jump to the crash frame
(gdb) print var   # inspect locals
```

---

## Step 3 — The usual suspects

| Symptom | Likely cause |
|---------|--------------|
| Crash on first deref | NULL pointer |
| Crash on second run | Use-after-free OR uninitialized pointer |
| Crash in printf | Bad format specifier (`%s` for non-string, missing arg) |
| Crash in strlen / strcpy | Missing `\0` terminator |
| Crash deep in libc | You smashed the heap somewhere earlier |
| Stack overflow | Infinite recursion |

---

## Step 4 — When ASan + gdb give nothing

Heap corruption can crash far from the bug. Try:
- `valgrind ./a.out` (slower than ASan but catches different things)
- Reduce the test case until it crashes deterministically
- Print pointer values before each deref. Boring. Works.

---

## See also

- [lessons/02-pointers/06-common-pointer-bugs.c](../lessons/02-pointers/06-common-pointer-bugs.c)
- [mnemonics/POINTERS_101.txt](../mnemonics/POINTERS_101.txt)
