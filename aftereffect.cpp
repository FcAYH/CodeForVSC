#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, max, min, sum;

int num[10][10];
void move(int m)
{
    int a, i;
    a = num[m][n];
    for (i = n - 1; i >= 1; i--)
    {
        num[m][i + 1] = num[m][i];
    }
    num[m][1] = a;
}
void dfs(int k)
{
    int i, j;
    if (k == n + 1)
    {
        max = 0;
        for (i = 1; i <= n; i++)
        {
            sum = 0;
            for (j = 1; j <= n; j++)
            {
                sum = sum + num[j][i];
            }
            if (sum > max)
            {
                max = sum;
            }
        }
        if (max < min)
        {
            min = max;
        }
        return;
    }
    for (i = 1; i <= n; i++)
    {
        move(k);
        dfs(k + 1);
    }
}
int main()
{
    int i, j;
    while ((scanf("%d", &n) != EOF) && (n != -1))
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                scanf("%d", &num[i][j]);
            }
        }
        max = 0;
        min = 0x7fffffff;
        dfs(2);
        printf("%d\n", min);
    }
    return 0;
}
/*
3
2 3 5
5 4 6
3 2 7
-1
*/
