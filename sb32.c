#include <stdio.h>

int POW(int x, int y)
{
    if (y == 0)
        return 1;
    else
        for (int i = 2; i <= y; i++)
            x *= 10;
    return x;
}

void Solve()
{
    printf("Please input a:");
    int a;
    scanf("%d", &a);
    while (a < 1 || a > 9)
        scanf("%d", &a);

    printf("Please input n:");
    int n;
    scanf("%d", &n);
    while (n < 0 || n > 10)
        scanf("%d", &n);

    int sum = 0;
    printf("Sum=");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%ld", a);
            sum += a * POW(10, j - 1);
        }
        if (i != n)
            printf("+");
    }
    puts("");

    printf("Sum=%ld", sum);
}

int main()
{
    Solve();

    return 0;
}
