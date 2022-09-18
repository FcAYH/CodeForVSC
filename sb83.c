#include <stdio.h>

void Solve()
{
    long int sum = 0;
    for (int i = 1; i <= 10; i++)
        sum += i * i * i;
    printf("sum=%ld\n", sum);
}

int main()
{
    Solve();

    return 0;
}
