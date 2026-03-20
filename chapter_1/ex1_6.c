#include <stdio.h>

int main(void)
{
    int c = EOF;
    while (EOF != (c = getchar())) {
        printf("%d", EOF != c);
    }
    printf("%d", EOF != c);

    return 0;
}
