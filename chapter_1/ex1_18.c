#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

static int getline(char line[], int max)
{
    int i       = 0;
    int c       = EOF;

    for (i = 0; i < max - 2 && EOF != (c = getchar()) && '\n' != c; ++i) {
        line[i] = (char)c;
    }

    if ('\n' == c) {
        line[i++] = (char)c;
    }

    line[i] = '\0';
    return i;
}

[[maybe_unused]]
static void debug_print(char line[])
{
    for (int i = 0; line[i]; ++i) {
        if (line[i] == ' ' || line[i] == '\t') {
            putchar('*');
        }
        else {
            putchar(line[i]);
        }
    }
}

static void trim(char line[])
{
    int last_char   = 0;
    int i           = 0;

    for (; line[i]; ++i) {
        if (!isspace(line[i])) {
            last_char = i + 1;
        }
    }

    line[last_char] = '\0';
}

int main(void)
{
    char line[MAXLINE];
    int linelen = 0;

    while ((linelen = getline(line, MAXLINE)) > 0) {
        trim(line);
        if (line[0]) {
            printf("%s\n", line);
        }
    }

    return 0;
}
