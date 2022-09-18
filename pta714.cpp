#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <cstdlib>
using namespace std;
typedef pair<int,int> pii;
priority_queue < pii, vector<pii>, greater<pii> > q;
int n,m,s,t;
int step[4040400],tot[4040400],f[4040400],dis[4040400],path[4040000],rec[4040000];
bool vis[4040000];
int head[4004000];
struct list
{
    int to,nxt,w;
}e[8040000];
int read()
{
    char key[5];
    for(int i = 0; i <= 4; i++) key[i] = 0;
    scanf("%s",key);
    int rt = key[0] * 10000 + key[1] * 100 + key[2];
    return rt;
}

void add_edge(int u, int v, int w)
{
    e[++head[0]].to = v;
    e[head[0]].nxt = head[u];
    e[head[0]].w = w;
    head[u] = head[0];
}

void print(int x)
{
    if(path[x])    print(path[x]);
    int c1 = x / 10000, c3 = x % 100;
    int c2 = (x - c1 * 10000 - c3) / 100;
    if(x != t) printf("%c%c%c->",c1,c2,c3);
    else    printf("%c%c%c\n",c1,c2,c3);
}
int main()
{
    scanf("%d%d",&n,&m);
    s = read(), t = read();
    for(int i = 1; i < n; i++)
    {
        int w;
        int num = read();
        scanf("%d",&w);
        f[num] = w;
    }
    for(int i = 1; i <= m; i++)
    {
        int u = read(), v = read(), w;
        scanf("%d",&w);
        add_edge(u, v, w), add_edge(v, u, w);
    }
    for(int i = 0; i <= 4000000; i++) dis[i] = 2e9;
    dis[s] = 0, step[s] = 1, tot[s] = f[s],  rec[s] = 1;
    q.push(make_pair(dis[s],s));
    while(!q.empty())
    {
        int x = q.top().second;
        q.pop();
        for(int i = head[x]; i; i = e[i].nxt)
        {
            int v = e[i].to;
            if(dis[x] + e[i].w < dis[v])
            {
                dis[v] = dis[x] + e[i].w;
                step[v] = step[x] + 1;
                tot[v] = tot[x] + f[v];
                path[v] = x;
                rec[v] = rec[x];
                q.push(make_pair(dis[v], v));
            }
            else if(dis[x] + e[i].w == dis[v] && step[x] + 1 > step[v])
            {
                step[v] = step[x] + 1;
                tot[v] = tot[x] + f[v];
                path[v] = x;
                rec[v] += rec[x];
                q.push(make_pair(dis[v], v));
            }
            else if(dis[x] + e[i].w == dis[v] && step[x] + 1 == step[v] && tot[x] + f[v] > tot[v])
            {
                tot[v] = tot[x] + f[v];
                path[v] = x;
                rec[v] += rec[x];
                q.push(make_pair(dis[v], v));
            }
            else if(dis[x] + e[i].w == dis[v] )
            {
                rec[v] += rec[x];
                q.push(make_pair(dis[v], v));
            }
        }
    }
    print(t);
    printf("%d %d %d",rec[t],dis[t],tot[t]);
    system("pause");
    return 0;
}