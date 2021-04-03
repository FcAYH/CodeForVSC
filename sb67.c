#include <stdio.h>

int cnt = 0;

int Fib(int x)
{
    cnt++;

    if (x == 0)
        return 0;
    if (x == 1)
        return 1;

    return Fib(x - 1) + Fib(x - 2);
}

void Solve()
{
    printf("Input n:");
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        cnt = 0;
        int ans = Fib(i);
        printf("Fib(%d)=%d, count=%d\n", i, ans, cnt);
    }
}

int main()
{
    Solve();

    return 0;
}
