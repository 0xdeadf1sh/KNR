#include <stdio.h>

#define MAXLINE 50

static int getline(char line[], int max)
{
    int i       = 0;
    int lineind = 0;
    int c       = EOF;

    for (i = 0; EOF != (c = getchar()) && '\n' != c; ++i) {
        if (i < max - 2) {
            line[lineind++] = (char)c;
        }
    }

    if ('\n' == c) {
        line[lineind++] = (char)c;
    }

    line[lineind] = '\0';
    return i;
}

int main(void)
{
    char line[MAXLINE];
    int linelen = 0;

    while ((linelen = getline(line, MAXLINE)) > 0) {
        printf("%d: %s", linelen, line);
    }

    return 0;
}
