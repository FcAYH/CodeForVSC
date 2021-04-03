#include <stdio.h>

int check(int x)
{
    int sum = 0;
    for (int i = 1; i <= x - 1; i++)
    {
        if (!(x % i))
            sum += i;
    }
    return (sum == x) ? 1 : 0;
}

void Make_Ans(int x)
{
    for (int i = 1; i <= x - 1; i++)
    {
        if (!(x % i))
            printf("%5d", i);
    }
}

void Solve()
{
    for (int i = 1; i <= 1000; i++)
    {
        if (check(i))
            printf("\n%5d\n", i), Make_Ans(i);
    }
}

int main()
{
    Solve();

    return 0;
}
