#include <stdio.h>

#define CURRENT 1000000

void Solve()
{
    printf("Input grow rate:");
    double growRate;
    scanf("%lf", &growRate);

    int year = 0, output = CURRENT;
    while (output < 2 * CURRENT)
    {
        output = output * (1 + growRate);
        year++;
    }
    printf("When grow rate is %.0f%%, the output can be doubled after %d years.\n", growRate * 100, year);
}

int main()
{
    Solve();

    return 0;
}
