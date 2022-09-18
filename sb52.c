#include <stdio.h>

#define Inf 0x3f3f3f3f

int Mymax(int x, int y)
{
    return (x > y) ? x : y;
}

void Solve()
{
    printf("input ten integer");

    int Max = -Inf, n;
    for (int i = 1; i <= 10; i++)
        scanf("%d", &n), Max = Mymax(Max, n);

    printf("%d\n", Max);
}

int main()
{
    Solve();

    return 0;
}
