#include <bits/stdc++.h>

using namespace std;

const int Maxn = 300;

int n, m;
int upper[Maxn][Maxn];
int torig[Maxn][Maxn];
int Ans[Maxn][Maxn];

void Dp()
{
    Ans[1][1] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (upper[i][j] != -1)
                Ans[i + 1][j] += Ans[i][j];
            if (torig[i][j] != -1)
                Ans[i][j + 1] += Ans[i][j];
        }
    }

    printf("%d\n", Ans[n][m]);
}

void Solve()
{
    scanf("%d%d", &n, &m);
    n++, m++;

    int ope;
    scanf("%d", &ope);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            upper[i][j] = i + 1;
            torig[i][j] = j + 1;
        }
    }
    for (int i = 1; i <= ope; i++)
    {
        int x, y, R, L;
        scanf("%d%d%d%d", &x, &y, &R, &L);

        for (int k = y; k < y + L; k++)
            for (int j = x + 1; j < x + R; j++)
                torig[j][k] = -1;

        for (int j = x; j < x + R; j++)
            for (int k = y + 1; k < y + L; k++)
                upper[j][k] = -1;

        Dp();
    }
}

int main()
{
    Solve();

    return 0;
}

/*
5 6
1
2 4 3 2
*/