#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int Maxn = 100010;
const int Maxm = 300010;
const int Inf = 2147483647;
int num = 0, n, m, s, u, v, w;
int head[Maxn];
int len = 0;
bool vis[Maxn];
int dis[Maxn];
struct Heap
{
    int v, num;
} h[Maxn];
struct EDGE
{
    int to, next, v;
} E[Maxm];
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
inline void add_edge(int x, int y, int vt)
{
    E[++num].next = head[x], E[num].to = y, E[num].v = vt, head[x] = num;
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
    return (h[1].v == 0 && h[1].num == 0) ? 1 : 0;
}
void dijkstra(int poi)
{
    for (int i = 1; i <= n; i++)
        dis[i] = Inf;
    dis[poi] = 0;
    insert(poi);
    while (!write_empty())
    {
        int st = h[1].num;
        destory(1);
        if (vis[st] == true)
            continue;
        vis[st] = true;
        for (int i = head[st]; i; i = E[i].next)
        {
            int qt = E[i].to, val = E[i].v;
            if (dis[qt] > dis[st] + val && vis[qt] == false)
            {
                dis[qt] = dis[st] + val;
                insert(qt);
            }
        }
    }
}
int main()
{
    n = read();
    m = read();
    s = read();
    for (int i = 1; i <= m; i++)
    {
        u = read();
        v = read();
        w = read();
        add_edge(u, v, w);
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++)
        printf("%d ", dis[i]);
    return 0;
}
