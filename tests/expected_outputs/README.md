# Expected Outputs

Golden outputs. Test runner compares actual stdout to these.

File naming: `<topic>_<lessonfile>.txt` (slashes replaced with `_`, `.c` -> `.txt`).

Excluded (non-deterministic or input-dependent):
- `02-pointers/01-address-and-dereference` — prints addresses
- `02-pointers/05-double-pointers` — prints argv path
- `03-memory/01-stack-vs-heap` — addresses
- `06-file-io/*` — depends on file presence
- `projects/guess/*` — random + stdin
- `projects/phonebook/*` — stdin + file

Add new expected file when adding a deterministic lesson.
