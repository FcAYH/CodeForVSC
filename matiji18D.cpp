#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MaxN = 100010;

struct Edge
{
    int to, next;
    ll val;
};
Edge edge[MaxN << 1];

int num = 0;
int head[MaxN];
ll dis[MaxN];

void AddEdge(int x, int y, ll v)
{
    edge[++num].next = head[x];
    edge[num].to = y;
    edge[num].val = v;
    head[x] = num;
}

void dfs(int point, int fa)
{
    for (int i = head[point]; i; i = edge[i].next)
    {
        int qt = edge[i].to;
        if (qt == fa)
            continue;
        dis[qt] = dis[point] + edge[i].val;
        dfs(qt, point);
    }
}

void Solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        AddEdge(x, y, (ll)w);
        AddEdge(y, x, (ll)w);
    }

    memset(dis, 0, sizeof(dis));
    dfs(1, 0);

    ll maxDis = 0;
    int point = 0;
    for (int i = 1; i <= n; i++)
    {
        if (maxDis < dis[i])
        {
            maxDis = dis[i];
            point = i;
        }
    }

    memset(dis, 0, sizeof(dis));
    dfs(point, 0);
    for (int i = 1; i <= n; i++)
    {
        maxDis = max(maxDis, dis[i]);
    }
    printf("%lld", maxDis);
}

int main()
{
    Solve();

    return 0;
}
