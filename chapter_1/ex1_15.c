#include <stdio.h>

#define LOWER   0.0f
#define UPPER   300.0f
#define STEP    20.0f

static float fahr_to_celsius(float fahr)
{
    return (5.0f / 9.0f) * (fahr - 32.0f);
}

int main(void)
{
    printf("  FAHR     CELSIUS\n");
    for (float fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        float celsius = fahr_to_celsius(fahr);
        printf("%6.0f %10.2f\n", fahr, celsius);
    }

    return 0;
}
