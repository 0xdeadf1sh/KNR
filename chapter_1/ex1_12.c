#include <stdio.h>
#include <ctype.h>

#define IN_WORD     1
#define OUT_WORD    0

int main(void)
{
    int c       = EOF;
    int state   = OUT_WORD;

    while (EOF != (c = getchar())) {
        if (isspace(c)) {
            if (IN_WORD == state) {
                state = OUT_WORD;
                putchar('\n');
            }
        }
        else {
            state = IN_WORD;
            putchar(c);
        }
    }

    return 0;
}
