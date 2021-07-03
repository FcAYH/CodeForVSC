#include <bits/stdc++.h>

using namespace std;

const int Maxn = 15;

int n, counter = 0;
int vis[Maxn], rec[Maxn];

void dfs(int cur)
{
    if (cur == n + 1)
    {
        counter++;
        for (int i = 1; i <= n; i++)
            printf("%d ", rec[i]);
        puts("");

        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            rec[cur] = i;
            dfs(cur + 1);
            vis[i] = 0;
        }
    }
}

void Solve()
{
    scanf("%d", &n);

    dfs(1);

    printf("%d\n", counter);
}

int main()
{
    Solve();

    return 0;
}
