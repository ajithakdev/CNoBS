# Onboarding — CNoBS

Goal: compile + run your first `.c` file in **under 5 minutes**.

---

## Step 1 — Install a C compiler

You only need ONE of these. Pick by OS.

### Windows

**Easiest: Clang via winget**
```powershell
winget install -e --id LLVM.LLVM
```
Close + reopen your terminal after install. Verify:
```powershell
clang --version
```

**Alternative: gcc via MSYS2**
```powershell
winget install -e --id MSYS2.MSYS2
```
Open the **MSYS2 UCRT64** terminal, then:
```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
```
Add `C:\msys64\ucrt64\bin` to your PATH. Restart terminal. Verify:
```powershell
gcc --version
```

### macOS
```bash
xcode-select --install
```
Gives you `clang`. Verify: `clang --version`.

### Linux (Debian/Ubuntu)
```bash
sudo apt update && sudo apt install build-essential
```
Verify: `gcc --version`.

---

## Step 2 — Clone the repo

```bash
git clone <repo-url> CNoBS
cd CNoBS
```

---

## Step 3 — Compile + run your first lesson

### Windows (PowerShell, using clang)
```powershell
cd lessons
clang 01-output-first.c -o out.exe
./out.exe
```
One-liner:
```powershell
clang 01-output-first.c -o out.exe; if ($?) { ./out.exe }
```

### Windows (PowerShell, using gcc from MSYS2)
```powershell
cd lessons
gcc 01-output-first.c -o out.exe
./out.exe
```

### macOS / Linux / WSL / Git Bash
```bash
cd lessons
gcc 01-output-first.c && ./a.out
```
(Use `clang` instead of `gcc` on macOS if you prefer — same flags.)

**Expected output:**
```
x = 5, y = 3
sum = 8
x is bigger
counting: 0 1 2 3 4
```

If you see that — setup done. You're coding C.

---

## Step 4 — Learning path

Do them in order. Each takes 10-15 min.

```
lessons/01-output-first.c     <- start
lessons/02-pointers-visual.c
lessons/03-arrays-memory.c
lessons/04-structs.c
        |
challenges/01-fix-the-loop.c  <- find + fix bugs
challenges/02-pointer-puzzle.c
        |
patterns/string-search.c      <- real-code snippet
        |
projects/guess/guess.c        <- first real program
projects/phonebook/phonebook.c
```

**How to use a lesson:**
1. Read top comment. **Don't read the code yet.**
2. Predict the output from the expected-output block.
3. Read the code. See if you guessed right.
4. Run it. Confirm.
5. Do the **BREAK IT** section at the bottom. Change one thing. Run again.

If a lesson takes more than 20 min, skip the BREAK IT and come back. Don't stall.

---

## Step 5 — Common gotchas

| Symptom | Fix |
|---------|-----|
| `'gcc' is not recognized` (Windows) | Compiler not on PATH. Reopen terminal after install. Or use `clang`. |
| `&&` parser error in PowerShell 5.1 | Use `; if ($?) { ... }` instead. Or upgrade to PowerShell 7. |
| `a.out` not found on Windows | Windows builds `a.exe`. Use `./a.exe` or compile with `-o name.exe`. |
| Segfault | You dereferenced a bad pointer. Go back to [lessons/02-pointers-visual.c](lessons/02-pointers-visual.c). |
| Garbage output | Probably uninitialized variable or buffer overrun. Read the BREAK IT note in lesson 03. |
| `undefined reference to ...` | Forgot to `#include` a header, or function name typo. |

---

## Step 6 — Editor (optional)

Any text editor works. Recommended:
- **VS Code** + the **C/C++** extension (Microsoft). Syntax highlighting, jump-to-definition.
- **Vim / Neovim** with `clangd`.
- **Notepad** literally works. C doesn't care.

No project file. No build system. One file, one command.

---

## You're done

Run lesson 01 now. If it prints the expected output, close this file and start learning.

Stuck? Open an issue with: OS, compiler version, the exact error.

---

Maintainer: **[ajithakdev](https://github.com/ajithakdev)** · ajithkumarks2579@gmail.com / cseajithak@gmail.com
