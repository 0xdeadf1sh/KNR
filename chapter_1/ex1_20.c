#include <stdio.h>

#define TABSTOP 8

static void print_spaces(int space_count)
{
    for (int i = 0; i < space_count; ++i) {
        putchar(' ');
    }
}

int main(void)
{
    int c = EOF;
    int i = 0;

    while (EOF != (c = getchar())) {

        if ('\n' == c) {
            i = 0;
            putchar(c);
        }
        else if ('\t' == c) {
            int num_spaces = TABSTOP - i % TABSTOP;
            print_spaces(num_spaces);
            i += num_spaces;
        }
        else {
            ++i;
            putchar(c);
        }

    }

    return 0;
}
