## What changed
<!-- 1-3 bullets. What + why. No essay. -->
-

## Type
<!-- check one -->
- [ ] new lesson / practice / pattern
- [ ] fix (compile / output / typo)
- [ ] docs
- [ ] infra (Makefile / CI / tests)

---

## Developer checklist

- [ ] `make compile-check` passes locally
- [ ] `make test` passes locally
- [ ] New `.c` file follows lesson template (≤30 lines, output-first, BREAK IT)
- [ ] If deterministic: added matching `tests/expected_outputs/<key>.txt`
- [ ] Linked from the topic `README.md` (if a new lesson)
- [ ] No secrets, no personal data, no large binaries

## Reviewer checklist

- [ ] CI green (compile-check + test)
- [ ] Tone matches repo (punchy, no fluff, no "learning journey")
- [ ] WHY comments only, no WHAT narration
- [ ] Memory diagram present where pointers/memory touched
- [ ] Golden output matches reality (not aspirational)
- [ ] No dead refs (links, file paths)
