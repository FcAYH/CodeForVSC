#include <stdio.h>

void Solve()
{
    printf("请输入树的层数：");
    int n;
    scanf("%d", &n);

    int st = 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= st; j++)
        {
            for (int k = 1; k <= n - j + 1; k++)
                printf(" ");
            for (int k = 1; k <= j * 2 - 1; k++)
                printf("*");
            puts("");
        }
        st++;
    }
    for (int i = 1; i <= n; i++)
        printf(" ");
    printf("|\n");
    for (int i = 1; i <= n; i++)
        printf("=");
    printf("V");
    for (int i = 1; i <= n; i++)
        printf("=");
}

int main()
{
    Solve();

    return 0;
}
