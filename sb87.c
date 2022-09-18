#include <stdio.h>

void Solve()
{
    int Num[40];
    for (int i = 1; i <= 30; i++)
        Num[i] = i * 2;

    int sum = 0;
    for (int i = 1; i <= 30; i++)
    {
        if (!(i % 5))
            printf("%6d", Num[i - 2]);
    }
}

int main()
{
    Solve();

    return 0;
}
