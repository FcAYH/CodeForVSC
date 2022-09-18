#include <stdio.h>

#define N 12

void Transpose(int a[][N], int n);
void InputMatrix(int a[][N], int n)
{
    printf("Input %d*%d matrix:\n", n, n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
}
void PrintMatrix(int a[][N], int n)
{
    printf("The transposed matrix is:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%d\t", a[j][i]);
        puts("");
    }
}

void Solve()
{
    int n = 0;
    printf("Input n:\n");
    scanf("%d", &n);

    int a[20][N];
    InputMatrix(a, n);
    PrintMatrix(a, n);
}

int main()
{
    Solve();

    return 0;
}
