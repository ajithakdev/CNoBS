/*
 * Capstone tests. Compile + run, no external framework.
 *
 * Build:
 *   gcc capstone_test.c -o capstone_test
 *   ./capstone_test
 *
 * EXPECTED OUTPUT:
 *   capstone_test: 10 passed, 0 failed.
 *
 * This file vendors the parser via a copy of the public functions
 * so we can test without linking. In a real project we'd extract a header.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct { const char *src; int pos; int err; } Parser;

static void skip_ws(Parser *p) {
    while (p->src[p->pos] == ' ' || p->src[p->pos] == '\t') p->pos++;
}
static int parse_expr(Parser *p);
static int parse_factor(Parser *p) {
    skip_ws(p);
    char c = p->src[p->pos];
    if (c == '(') { p->pos++; int v = parse_expr(p); skip_ws(p);
        if (p->src[p->pos] != ')') { p->err = 1; return 0; } p->pos++; return v; }
    if (c == '-') { p->pos++; return -parse_factor(p); }
    if (!isdigit((unsigned char)c)) { p->err = 1; return 0; }
    int v = 0;
    while (isdigit((unsigned char)p->src[p->pos])) { v = v*10 + (p->src[p->pos]-'0'); p->pos++; }
    return v;
}
static int parse_term(Parser *p) {
    int v = parse_factor(p);
    for (;;) {
        skip_ws(p);
        char c = p->src[p->pos];
        if (c != '*' && c != '/') return v;
        p->pos++;
        int r = parse_factor(p);
        if (c == '*') v *= r;
        else { if (r == 0) { p->err = 1; return 0; } v /= r; }
    }
}
static int parse_expr(Parser *p) {
    int v = parse_term(p);
    for (;;) {
        skip_ws(p);
        char c = p->src[p->pos];
        if (c != '+' && c != '-') return v;
        p->pos++;
        int r = parse_term(p);
        if (c == '+') v += r; else v -= r;
    }
}
static int eval(const char *expr, int *out) {
    Parser p = { expr, 0, 0 };
    int v = parse_expr(&p);
    skip_ws(&p);
    if (p.err || p.src[p.pos] != '\0') return -1;
    *out = v;
    return 0;
}

static int passed = 0, failed = 0;

static void check(const char *expr, int want) {
    int got;
    if (eval(expr, &got) != 0) {
        printf("  FAIL: %s -> parse error (want %d)\n", expr, want);
        failed++;
        return;
    }
    if (got != want) {
        printf("  FAIL: %s -> %d (want %d)\n", expr, got, want);
        failed++;
    } else {
        passed++;
    }
}
static void check_err(const char *expr) {
    int got;
    if (eval(expr, &got) == 0) {
        printf("  FAIL: %s -> %d (wanted parse error)\n", expr, got);
        failed++;
    } else {
        passed++;
    }
}

int main(void) {
    check("1+2", 3);
    check("3 + 5 * 2", 13);
    check("(3 + 5) * 2", 16);
    check("3 + 5 * (2 - 8) / 2", -12);
    check("-7 + 3", -4);
    check("100 / 10 / 2", 5);
    check("2*3+4*5", 26);
    check("   42   ", 42);
    check_err("1 +");
    check_err("(1 + 2");

    printf("capstone_test: %d passed, %d failed.\n", passed, failed);
    return failed == 0 ? 0 : 1;
}
