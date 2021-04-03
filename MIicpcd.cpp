#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int Maxn = 400021;

#define min(a, b) a < b ? a : b
#define max(a, b) a > b ? a : b

vector<int> e[Maxn];

int low[Maxn];
int dfn[Maxn];
int Time;
int block[Maxn];
int CNT = 0;

void tarjan(int u)
{
    int v;
    dfn[u] = low[u] = ++Time;
    for (int i = 0; i < e[u].size(); i++)
    {
        v = e[u][i];
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);

            if (dfn[u] <= low[v])
                block[u]++;
        }
        else
            low[u] = min(low[u], dfn[v]);
    }
}

int vis[Maxn];

inline void dfs(int poi)
{
    vis[poi] = 1;
    int top = e[poi].size() - 1;
    for (int i = 0; i <= top; i++)
    {
        if (!vis[e[poi][i]])
        {
            dfs(e[poi][i]);
        }
    }
}

void Solve()
{
    int u, v, n, m;

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        Time = 0;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        block[i] = 1;
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            block[i] = 0, tarjan(i), CNT++;

    //printf("Network #%d\n", ++count);
    //printf("%d ", CNT);

    int flag = 0;
    for (int i = 1; i <= n; i++)
        printf("%d ", CNT + block[i] - 1);
}

int main()
{
    Solve();
    system("pause");
    return 0;
}
