#include <stdio.h>

int main(void)
{
    int c       = EOF;
    int lastc   = c;

    while (EOF != (c = getchar())) {
        if (c != ' ') {
            if (lastc == ' ') {
                putchar(' ');
            }
            putchar(c);
        }

        lastc = c;
    }
}
