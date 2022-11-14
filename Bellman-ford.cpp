#include <bits/stdc++.h>

using namespace std;

const int MaxN = 10010;
const int MaxM = 500010;

int num = 0;
int dis[MaxN];
int head[MaxN];

struct Edge
{
    int next, from, to, v;
} edge[MaxM];

void Add_Edge(int x, int y, int v)
{
    edge[++num].next = head[x];
    edge[num].from = x;
    edge[num].to = y;
    edge[num].v = v;
    head[x] = num;
}

void Bellman_Ford(int n, int start)
{
    memset(dis, 0x3f, sizeof(dis));
    dis[start] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            int stp = edge[j].from;
            int dest = edge[j].to;
            if (dis[dest] > dis[stp] + edge[j].v)
                dis[dest] = dis[stp] + edge[j].v;
        }
    }
}

void Solve()
{
    int n, m, start;
    scanf("%d%d%d", &n, &m, &start);
    start--;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u--, v--;
        Add_Edge(u, v, w);
    }

    Bellman_Ford(n, start);

    for (int i = 0; i < n; i++)
    {
        if (dis[i] == 0x3f3f3f3f)
            printf("2147483647 ");
        else
            printf("%d ", dis[i]);
    }
}

int main()
{
    Solve();

    return 0;
}

/*
5 8
0 1 2
1 2 3
0 2 1
0 3 5
1 3 4
1 4 3
2 3 4
2 4 2
0
*/
