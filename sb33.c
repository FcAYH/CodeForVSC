#include <stdio.h>

void Solve()
{
    int sum = 0;
    for (int i = 1; i <= 99; i += 2)
        sum += i * (i + 1) * (i + 2);
    printf("sum = %ld\n", sum);
}

int main()
{
    Solve();

    return 0;
}
