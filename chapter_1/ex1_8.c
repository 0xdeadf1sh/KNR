#include <stdio.h>

int main(void)
{
    int nblanks     = 0;
    int ntabs       = 0;
    int nlines      = 0;

    int c           = EOF;

    while (EOF != (c = getchar())) {
        if (' ' == c) {
            ++nblanks;
        }
        else if ('\t' == c) {
            ++ntabs;
        }
        else if ('\n' == c) {
            ++nlines;
        }
    }

    printf("nblanks = %d, ntabs = %d, nlines = %d\n", nblanks,
                                                      ntabs,
                                                      nlines);

    return 0;
}
