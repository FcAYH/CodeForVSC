#include <bits/stdc++.h>

using namespace std;

const int MaxN = 202;

char ans[MaxN][MaxN];

void Solve()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            if (i == j || i + j == 2 * n - 2)
                ans[i][j] = '*';
            else if (j == 0 && i < n)
                ans[i][j] = '*';
            else if (j == 2 * n - 2 && i >= n - 1)
                ans[i][j] = '*';
            else if (i == 0 && j >= n - 1)
                ans[i][j] = '*';
            else if (i == 2 * n - 2 && j < n)
                ans[i][j] = '*';
            else if (i == n - 1)
                ans[i][j] = '*';
            else if (j == n - 1)
                ans[i][j] = '*';
        }
    }

    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            if (ans[i][j] != '*')
                printf(" ");
            else
                printf("%c", ans[i][j]);
        }
        puts("");
    }
}

int main()
{
    Solve();

    return 0;
}
