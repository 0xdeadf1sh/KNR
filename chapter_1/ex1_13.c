#include <stdio.h>
#include <ctype.h>

#define WORD_MAXLEN     100
#define IN_WORD         1
#define OUT_WORD        0

int main(void)
{
    int wordfreqs[WORD_MAXLEN]  = {};
    int state                   = OUT_WORD;
    int c                       = EOF;
    int charcount               = 0;

    while (EOF != (c = getchar())) {
        if (isspace(c)) {
            if (IN_WORD == state) {
                state = OUT_WORD;
                if (charcount > 0 && charcount < WORD_MAXLEN) {
                    ++wordfreqs[charcount];
                }
                charcount = 0;
            }
        }
        else {
            state = IN_WORD;
            ++charcount;
        }
    }

    // horizontal histogram

    for (int i = 1; i < WORD_MAXLEN; ++i) {
        if (wordfreqs[i]) {
            printf("%3d %3d: ", i, wordfreqs[i]);
            for (int j = 0; j < wordfreqs[i]; ++j) {
                putchar('|');
            }
            putchar('\n');
        }
    }

    // vertical histogram

    int maxfreq = 0;
    for (int i = 1; i < WORD_MAXLEN; ++i) {
        if (wordfreqs[i] > maxfreq) {
            maxfreq = wordfreqs[i];
        }
    }

    int tmp = maxfreq;
    for (int i = 0; i < maxfreq; ++i) {
        for (int j = 1; j < WORD_MAXLEN; ++j) {
            if (wordfreqs[j] > 0) {
                if (wordfreqs[j] >= tmp) {
                    printf(" - ");
                }
                else {
                    printf("   ");
                }
            }
        }
        --tmp;
        putchar('\n');
    }

    for (int i = 1; i < WORD_MAXLEN; ++i) {
        if (wordfreqs[i] > 0) {
            printf("%2d ", wordfreqs[i]);
        }
    }

    putchar('\n');

    for (int i = 1; i < WORD_MAXLEN; ++i) {
        if (wordfreqs[i] > 0) {
            printf("%2d ", i);
        }
    }

    putchar('\n');

    return 0;
}
