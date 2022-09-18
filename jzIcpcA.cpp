#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int Maxn = 300;
const int Inf = 2147483647;
int q, e, n, m, s, u, v, w;
int len = 0;
bool vis[Maxn];
int dis[Maxn];
int dt[Maxn][Maxn];
int val[Maxn];

struct Heap
{
    int v, num;
} h[Maxn];

inline int read()
{
    int fl = 1, rt = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            fl = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        rt = rt * 10 + ch - '0';
        ch = getchar();
    }
    return fl * rt;
}

inline void insert(int poi)
{
    h[++len].v = dis[poi], h[len].num = poi;
    int si = 1, ilen = len;
    while (ilen >= 1 && si)
    {
        if (h[ilen >> 1].v > h[ilen].v)
            swap(h[ilen], h[ilen >> 1]);
        else
            si = 0;
        ilen >>= 1;
    }
}
inline void destory(int poi)
{
    h[1] = h[len];
    len--;
    int t, si = 1, ilen = 1;
    while ((ilen << 1) <= len && si)
    {
        if (h[ilen].v > h[ilen << 1].v || h[ilen].v > h[ilen << 1 | 1].v)
        {
            if (h[ilen << 1].v > h[ilen << 1 | 1].v && (ilen << 1 | 1) <= len)
                t = ilen << 1 | 1;
            else
                t = ilen << 1;
            swap(h[ilen], h[t]);
            ilen = t;
        }
        else
            si = 0;
    }
}
inline int write_empty()
{
    return !len;
}

void dijkstra(int poi)
{
    for (int i = 1; i <= n; i++)
        dis[i] = Inf;
    memset(vis, 0, sizeof(vis));
    dis[poi] = 0;
    insert(poi);
    while (!write_empty())
    {
        int st = h[1].num;
        destory(1);
        if (vis[st] == true)
            continue;
        vis[st] = true;
        // printf("start\n");
        for (int i = 1; i <= n; i++)
        {
            if (dis[i] > dis[st] + dt[st][i] && vis[i] == false &&
                (val[i] <= w || i == e))
            {
                // printf("<%d, %d, %d, %d>\n", st, i, val[i], w);
                dis[i] = dis[st] + dt[st][i];
                insert(i);
            }
        }
    }
}

void Solve()
{
    int t = read();
    for (int k = 1; k <= t; k++)
    {
        n = read();
        q = read();

        for (int i = 1; i <= n; i++)
            val[i] = read();

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dt[i][j] = read();

        printf("Case #%d:\n", k);
        for (int i = 1; i <= q; i++)
        {
            s = read();
            e = read();
            w = read();

            dijkstra(s);

            printf("%d\n", dis[e]);
        }
    }
}
int main()
{
    Solve();

    return 0;
}
