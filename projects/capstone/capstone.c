/*
 * Capstone: Expression Evaluator
 * Parses + evaluates integer expressions: 3 + 5 * (2 - 8) / 2
 *
 * Combines: strings (parse), recursion (grammar), pointers (cursor),
 * file I/O (read expressions from a file), error handling.
 *
 * Grammar (recursive descent, left-associative):
 *   expr   = term   (('+'|'-') term)*
 *   term   = factor (('*'|'/') factor)*
 *   factor = number | '(' expr ')' | '-' factor
 *
 * Run:
 *   gcc capstone.c -o capstone
 *   ./capstone "3 + 5 * 2"
 *   ./capstone --file exprs.txt
 *
 * EXAMPLE:
 *   $ ./capstone "3 + 5 * (2 - 8) / 2"
 *   -12
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    const char *src;
    int pos;
    int err;
} Parser;

static void skip_ws(Parser *p) {
    while (p->src[p->pos] == ' ' || p->src[p->pos] == '\t') p->pos++;
}

static int parse_expr(Parser *p);

static int parse_factor(Parser *p) {
    skip_ws(p);
    char c = p->src[p->pos];
    if (c == '(') {
        p->pos++;
        int v = parse_expr(p);
        skip_ws(p);
        if (p->src[p->pos] != ')') { p->err = 1; return 0; }
        p->pos++;
        return v;
    }
    if (c == '-') { p->pos++; return -parse_factor(p); }
    if (!isdigit((unsigned char)c)) { p->err = 1; return 0; }
    int v = 0;
    while (isdigit((unsigned char)p->src[p->pos])) {
        v = v * 10 + (p->src[p->pos] - '0');
        p->pos++;
    }
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
        else {
            if (r == 0) { p->err = 1; return 0; }
            v /= r;
        }
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
        if (c == '+') v += r;
        else          v -= r;
    }
}

int eval(const char *expr, int *out) {
    Parser p = { expr, 0, 0 };
    int v = parse_expr(&p);
    skip_ws(&p);
    if (p.err || p.src[p.pos] != '\0') return -1;
    *out = v;
    return 0;
}

static int eval_file(const char *path) {
    FILE *f = fopen(path, "r");
    if (!f) { fprintf(stderr, "could not open %s\n", path); return 1; }
    char buf[256];
    while (fgets(buf, sizeof(buf), f)) {
        size_t n = strlen(buf);
        while (n > 0 && (buf[n-1] == '\n' || buf[n-1] == '\r')) buf[--n] = '\0';
        if (n == 0) continue;
        int result;
        if (eval(buf, &result) == 0) printf("%s = %d\n", buf, result);
        else                         printf("%s = ERROR\n", buf);
    }
    fclose(f);
    return 0;
}

int main(int argc, char **argv) {
    if (argc == 3 && strcmp(argv[1], "--file") == 0) return eval_file(argv[2]);
    if (argc != 2) {
        fprintf(stderr, "usage: %s \"<expr>\"   or   %s --file <path>\n",
                argv[0], argv[0]);
        return 2;
    }
    int result;
    if (eval(argv[1], &result) != 0) {
        fprintf(stderr, "parse error\n");
        return 1;
    }
    printf("%d\n", result);
    return 0;
}
