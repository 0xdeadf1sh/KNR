#include <stdio.h>

#define MAXLINE 1000

static void reverse(char line[])
{
    int j = 0;

    for (; line[j] && line[j] != '\n'; ++j)
        ;

    if (line[j] == '\n')
        --j;

    for (int i = 0; i < j; ++i, --j) {
        char tmp = line[i];
        line[i] = line[j];
        line[j] = tmp;
    }
}

static int getline(char line[], int max)
{
    int i = 0;
    int c = EOF;

    for (; i < max - 2 && EOF != (c = getchar()) && '\n' != c; ++i)
        line[i] = (char)c;

    if (c == '\n')
        line[i++] = (char)c;

    line[i] = '\0';
    return i;
}

int main(void)
{
    char line[MAXLINE];
    int len = 0;

    while ((len = getline(line, MAXLINE))) {
        reverse(line);
        printf("%s", line);
    }

    return 0;
}
