#include <bits/stdc++.h>

using namespace std;

const int Maxn = 10;

int n;
int rec[Maxn][Maxn];

int Check()
{
    int counter = 0;
    for (int i = 1; i <= n; i++)
    {
        counter = 0;
        for (int j = 1; j <= n; j++)
            if (rec[j][i] == 1)
                counter++;

        if (counter > 1)
            return 0;
    }

    for (int sum = 2; sum <= 2 * n; sum++)
    {
        counter = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                if (i + j == sum && rec[j][i] == 1)
                    counter++;
        }
        if (counter > 1)
            return 0;
    }

    for (int sub = 1 - n; sub <= n - 1; sub++)
    {
        counter = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                if (i - j == sub && rec[j][i] == 1)
                    counter++;
        }
        if (counter > 1)
            return 0;
    }

    return 1;
}

void dfs(int i, int j)
{
    if (i == n)
    {
        if (Check())
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                    printf("%d ", rec[i][j]);
                puts("");
            }
            puts("");
        }

        return;
    }

    for (int k = j - 2; k >= 1; k--)
    {
        rec[i + 1][k] = 1;
        dfs(i + 1, k);
        rec[i + 1][k] = 0;
    }
    for (int k = j + 2; k <= n; k++)
    {
        rec[i + 1][k] = 1;
        dfs(i + 1, k);
        rec[i + 1][k] = 0;
    }
}

void Solve()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        rec[1][i] = 1;
        dfs(1, i);
        rec[1][i] = 0;
    }
}

int main()
{
    Solve();

    return 0;
}
