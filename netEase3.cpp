#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MaxN = 100010;
const int MaxM = 400010;
const ll INF = (ll)1e17;

struct Edge
{
    int to, next;
    ll val;
    bool flag;
} edge[MaxM];

int head[MaxN];
int num = 0;

int n, m;
ll dis[MaxN][2];
int vis[MaxN];

inline void addEdge(int x, int y, ll v, bool flag)
{
    edge[++num].next = head[x];
    edge[num].to = y;
    edge[num].val = v;
    edge[num].flag = flag;
    head[x] = num;
}

void Spfa()
{
    for (int i = 0; i < MaxN; i++)
        dis[i][0] = INF, dis[i][1] = INF;

    queue<int> q;

    dis[1][0] = 0;
    dis[1][1] = 0;
    q.push(1);
    vis[1] = 1;

    while (q.size() > 0)
    {
        int current = q.front();

        q.pop();
        vis[current] = 0;

        for (int i = head[current]; i; i = edge[i].next)
        {
            int to = edge[i].to;
            ll val = edge[i].val;
            if (edge[i].flag == true)
            {
                if (dis[to][0] > dis[current][0] + val)
                {
                    dis[to][0] = dis[current][0] + val;

                    if (!vis[to])
                        q.push(to);
                }

                if (dis[to][1] > dis[current][1] + val)
                {
                    dis[to][1] = dis[current][1] + val;

                    if (!vis[to])
                        q.push(to);
                }
            }
            else
            {
                // false

                if (dis[to][1] > dis[current][0] + val)
                {
                    dis[to][1] = dis[current][0] + val;

                    if (!vis[to])
                        q.push(to);
                }
            }
        }
    }
}

void Solve()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);

        addEdge(u, v, w, true);
        addEdge(v, u, w, false);
    }

    Spfa();

    if (dis[n][1] == INF && dis[n][0] == INF)
        printf("-1");
    else
        printf("%lld", min(dis[n][1], dis[n][0]));
}

int main()
{
    Solve();

    return 0;
}
