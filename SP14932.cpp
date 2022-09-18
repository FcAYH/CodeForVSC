#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn = 2000;
const int Maxm = 8000;
int t, n, m, num = 0;
int head[Maxn];
int depth[Maxn];
int A[Maxn][14];
struct EDGE
{
    int next, to;
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
inline void add_edge(int x, int y)
{
    E[++num].next = head[x], E[num].to = y, head[x] = num;
}
void Doubleincrease()
{
    for (int k = 1; k <= 11; k++)
    {
        for (int i = 1; i <= n; i++)
            A[i][k] = A[A[i][k - 1]][k - 1];
    }
}
inline void Array_Ini()
{
    num = 0;
    memset(head, 0, sizeof(head));
}
inline int LCA(int x, int y)
{
    if (depth[x] < depth[y])
        swap(x, y);
    int gap = depth[x] - depth[y];
    for (int i = 11; i >= 0; i--)
        if (gap & (1 << (i)))
            x = A[x][i];
    if (x == y)
        return x;
    for (int i = 11; i >= 0; i--)
        if (A[x][i] != A[y][i])
            x = A[x][i], y = A[y][i];
    return A[x][0];
}
void dfs(int poi, int fa)
{
    for (int i = head[poi]; i; i = E[i].next)
    {
        int qt = E[i].to;
        if (qt != fa)
        {
            A[qt][0] = poi;
            depth[qt] = depth[poi] + 1;
            dfs(qt, poi);
        }
    }
}
void Solve()
{
    t = read();
    for (int k = 1; k <= t; k++)
    {
        Array_Ini();
        n = read();
        int ch;
        for (int i = 1; i <= n; i++)
        {
            m = read();
            for (int j = 1; j <= m; j++)
                ch = read(), add_edge(ch, i), add_edge(i, ch);
        }
        depth[1] = 1;
        dfs(1, 0);
        Doubleincrease();
        int q, a, b;
        q = read();
        printf("Case %d:\n", k);
        for (int j = 1; j <= q; j++)
        {
            a = read(), b = read();
            printf("%d\n", LCA(a, b));
        }
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
1

7

3 2 3 4
0
3 5 6 7
0
0
0
0

2
5 7
2 7
*/
