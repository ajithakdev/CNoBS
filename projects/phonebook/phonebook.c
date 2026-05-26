/*
 * Project: Phonebook (intermediate)
 * Why this matters: Combines structs, arrays, file I/O, search, menu loop.
 * This is what "a real C program" looks like at ~100 lines.
 *
 * Run: gcc phonebook.c && ./a.out
 *
 * Stores contacts in `book.txt` (same folder). Persists between runs.
 *
 * MENU:
 *   1) add     2) list     3) find     4) quit
 *
 * SAMPLE:
 *   > 1
 *   name: Alice
 *   phone: 555-1234
 *   saved.
 *   > 3
 *   search name: ali
 *   Alice  555-1234
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define NAME_LEN 32
#define PHONE_LEN 20
#define FILE_PATH "book.txt"

struct Contact {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
};

static struct Contact book[MAX];
static int count = 0;

static int starts_with_ci(const char *s, const char *prefix) {
    for (int i = 0; prefix[i]; i++) {
        char a = s[i], b = prefix[i];
        if (a >= 'A' && a <= 'Z') a += 32;
        if (b >= 'A' && b <= 'Z') b += 32;
        if (a != b) return 0;
    }
    return 1;
}

static int contains_ci(const char *s, const char *needle) {
    for (int i = 0; s[i]; i++) {
        if (starts_with_ci(s + i, needle)) return 1;
    }
    return 0;
}

static void load(void) {
    FILE *f = fopen(FILE_PATH, "r");
    if (!f) return;
    while (count < MAX &&
           fscanf(f, "%31s %19s", book[count].name, book[count].phone) == 2) {
        count++;
    }
    fclose(f);
}

static void save(void) {
    FILE *f = fopen(FILE_PATH, "w");
    if (!f) { printf("save failed\n"); return; }
    for (int i = 0; i < count; i++) {
        fprintf(f, "%s %s\n", book[i].name, book[i].phone);
    }
    fclose(f);
}

static void add(void) {
    if (count >= MAX) { printf("full\n"); return; }
    printf("name: ");  scanf("%31s", book[count].name);
    printf("phone: "); scanf("%19s", book[count].phone);
    count++;
    save();
    printf("saved.\n");
}

static void list(void) {
    if (count == 0) { printf("(empty)\n"); return; }
    for (int i = 0; i < count; i++) {
        printf("%-16s %s\n", book[i].name, book[i].phone);
    }
}

static void find(void) {
    char q[NAME_LEN];
    printf("search name: ");
    scanf("%31s", q);
    int hits = 0;
    for (int i = 0; i < count; i++) {
        if (contains_ci(book[i].name, q)) {
            printf("%-16s %s\n", book[i].name, book[i].phone);
            hits++;
        }
    }
    if (!hits) printf("no matches\n");
}

int main(void) {
    load();
    int choice = 0;
    while (1) {
        printf("\n1) add  2) list  3) find  4) quit\n> ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }
        if      (choice == 1) add();
        else if (choice == 2) list();
        else if (choice == 3) find();
        else if (choice == 4) break;
        else printf("?\n");
    }
    return 0;
}

/*
 * Modify ideas:
 *   - Add a `delete` option (shift array down, save).
 *   - Sort the list alphabetically before printing.
 *   - Support names with spaces (use fgets instead of scanf %s).
 *   - Replace the linear `find` with a hash table (see future lesson).
 */
