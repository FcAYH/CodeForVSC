#include <bits/stdc++.h>

using namespace std;

const int Maxn = 30;
const int Inf = 0x3f3f3f3f;

int ans = Inf;
int n, m;
int vis[Maxn];
int Path[Maxn];
int tpath[Maxn];
int Map[Maxn][Maxn];

void dfs(int k, int poi, int val)
{
    if (k == n + 1)
    {
        if (val + Map[poi][m] < ans)
        {
            ans = val + Map[poi][m];

            for (int i = 2; i <= n; i++)
                Path[i] = tpath[i];
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                vis[i] = 1;
                tpath[k] = i;
                dfs(k + 1, i, val + Map[poi][i]);
                vis[i] = 0;
            }
        }
    }
}

void Solve()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &Map[i][j]);

    Path[1] = m;
    vis[m] = 1;
    dfs(2, m, 0);

    printf("%d\n", ans);
    for (int i = 1; i <= n; i++)
        printf("%d ", Path[i]);
    printf("%d\n", m);
}
int main()
{
    Solve();

    return 0;
}

/*
5 2
0 3 4 1 5
3 0 7 2 3
4 7 0 9 4
1 2 9 0 2
5 3 4 2 0
*/
