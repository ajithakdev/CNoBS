# Why C Still Matters in 2026

Not nostalgia. Not a take. The facts.

---

## What's written in C

- Linux, Windows NT kernel, macOS XNU (parts)
- SQLite, Redis, PostgreSQL (core)
- CPython, Ruby MRI, PHP, Lua, R
- nginx, OpenSSL, curl, git
- FFmpeg, ImageMagick, GIMP
- The standard library of every other language

Every program you run today touches a C codebase before its first instruction.

---

## What C teaches you that other languages hide

- **Memory has shape.** Stack vs heap. Alignment. Padding. Cache lines.
- **Pointers are just integers** with type metadata at compile time.
- **Strings are arrays.** Length is a walk.
- **The OS hands you bytes.** Files, sockets, malloc — all return bytes.

Once you've written C, Python's GIL, Go's escape analysis, Rust's borrow checker — they all stop being magic.

---

## When you'd actually write new C

- Kernels, drivers, embedded firmware
- Performance-critical libraries (codecs, crypto, parsers)
- Language runtimes
- Interop layers (FFI, glue code)
- Hardware-near tools (debuggers, tracing)

For most apps in 2026, write Rust, Go, or Zig instead. But you'll read C every day if you go deep on any system.

---

## The Rust question

Rust replaces C for memory safety + performance. It will keep eating the new-C-projects pie. Existing C is here for decades.

Learn C to **read the past**. Learn Rust to **write the future**. Both fit in the same brain.
