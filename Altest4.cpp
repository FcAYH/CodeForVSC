#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1000;
const int Inf = 0x3f3f3f3f;

int n, m;
int ans = 0;

int sel_amo = 0;
int vis[Maxn];
int w[Maxn], v[Maxn];
int selet[Maxn];

void dfs(int weight, int val)
{
    if (val > ans)
    {
        ans = val;

        int sel = 0;
        for (int i = 1; i <= n; i++)
            if (vis[i])
                selet[++sel] = i;
        sel_amo = sel;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && weight + w[i] <= m)
        {
            vis[i] = 1;
            dfs(weight + w[i], val + v[i]);
            vis[i] = 0;
        }
    }
}

void Solve()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        scanf("%d%d", &w[i], &v[i]);

    dfs(0, 0);

    printf("%d\n", ans);
    for (int i = 1; i <= sel_amo; i++)
        printf("%d ", selet[i]);
}

int main()
{
    Solve();

    return 0;
}

/*
5 100
20 5 
40 9 
10 3 
80 8 
30 6 
*/
