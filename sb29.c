#include <stdio.h>

void Solve()
{
    printf("input x:\n");

    float x, y = 0.0;
    scanf("%f", &x);

    if (x >= -7 && x <= 10)
    {
        y = 5 * x * x - 4 * x + 6;
        printf("y=%.3f", y);
    }
    else
    {
        y = 1.0 / 3.0 * x + 32.0;
        printf("y=%.3f", y);
    }
}

int main()
{
    Solve();

    while (1)
        ;

    return 0;
}
