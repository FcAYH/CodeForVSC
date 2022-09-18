#include <stdio.h>

#define Maxn 30

int A[Maxn][Maxn];

void Init()
{
    A[0][0] = 1;
    for (int i = 1; i <= Maxn - 1; i++)
        A[i][0] = 1;
    for (int i = 1; i <= Maxn - 1; i++)
    {
        for (int j = 1; j <= Maxn - 1; j++)
        {
            A[i][j] = A[i - 1][j] + A[i - 1][j - 1];
        }
    }
}

void Solve()
{
    Init();

    printf("input n (n<=10):\n");

    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= i; j++)
            printf("%4d", A[i][j]);
        puts("");
    }
}

int main()
{
    Solve();

    while (1)
        ;

    return 0;
}
