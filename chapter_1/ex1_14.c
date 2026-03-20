#include <stdio.h>
#include <ctype.h>

#define ASCII_LEN 256

int main(void)
{
    int asciifreq[ASCII_LEN]    = {};
    int c                       = EOF;

    while (EOF != (c = getchar())) {
        if (isprint(c)) {
            ++asciifreq[c];
        }
    }

    for (int i = 0; i < ASCII_LEN; ++i) {
        if (asciifreq[i]) {
            printf("'%c': ", i);
            for (int j = 0; j < asciifreq[i]; ++j) {
                putchar('|');
            }
            putchar('\n');
        }
    }

    return 0;
}
