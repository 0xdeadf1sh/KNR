#include <stdio.h>

#define LOWER   0.0f
#define UPPER   300.0f
#define STEP    20.0f

int main(void)
{
    printf("  CELSIUS    FAHR\n");
    for (float celsius = LOWER; celsius <= UPPER; celsius += STEP) {
        float fahr = (9.0f / 5.0f) * celsius + 32.0f;
        printf("%6.0f %10.2f\n", celsius, fahr);
    }

    return 0;
}
