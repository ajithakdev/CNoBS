/*
 * Practice: Tiny command interpreter. | Difficulty: hard
 *
 * Spec:
 *   set x 10
 *   set y 20
 *   add x y      -> prints 30
 *   print x      -> prints 10
 *
 * Run: gcc mini-interpreter.c && ./a.out
 *
 * EXPECTED TEST OUTPUT (when solved):
 *   30
 *   10
 */

#include <stdio.h>
#include <string.h>

#define VARS 26

static int env[VARS];

static int idx(char name) { return name - 'a'; }

void exec_line(const char *line) {
    /* TODO: tokenize. Dispatch on first word:
     *   set <var> <int>
     *   add <var1> <var2>     (print sum)
     *   print <var>
     */
    (void)line;
}

int main(void) {
    exec_line("set x 10");
    exec_line("set y 20");
    exec_line("add x y");
    exec_line("print x");
    (void)idx; (void)env;
    return 0;
}
