CC      ?= gcc
CFLAGS  ?= -Wall -Wextra -std=c11 -O0 -g

.PHONY: all test compile-check clean help

all: test

help:
	@echo "Targets:"
	@echo "  make compile-check   Compile every .c file (no run). Fails on warning."
	@echo "  make test            Compile + run + diff against expected_outputs."
	@echo "  make clean           Remove built binaries."

compile-check:
	@bash scripts/compile_check.sh

test:
	@bash tests/test_lessons.sh

clean:
	@find . -type f \( -name "*.o" -o -name "a.out" -o -name "*.exe" \) -delete
	@rm -rf tests/.build
	@echo "clean."
