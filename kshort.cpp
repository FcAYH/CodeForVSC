#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int, int> P;
const int maxn = 100000 + 7;
struct Edge
{
    int to, next, val;
} edge[maxn];
int n, m, head[maxn], dist[maxn][2], tot;
void addEdge(int a, int b, int c)
{
    edge[tot].to = b;
    edge[tot].val = c;
    edge[tot].next = head[a];
    head[a] = tot++;
}
void Dijkstra(int s)
{
    for (int i = 0; i <= n; i++)
        dist[i][0] = dist[i][1] = INF;
    dist[s][0] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, s));
    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        if (p.first > dist[p.second][1])
            continue;
        for (int i = head[p.second]; ~i; i = edge[i].next)
        {
            int d = p.first + edge[i].val;
            if (dist[edge[i].to][0] > d)
            {                                                 //更新最短路
                swap(dist[edge[i].to][0], d);                 //交换！！！
                que.push(P(dist[edge[i].to][0], edge[i].to)); //注意d值已经被交换了
            }
            if (dist[edge[i].to][1] > d && dist[edge[i].to][0] < d)
            { //更新次短路
                dist[edge[i].to][1] = d;
                que.push(P(d, edge[i].to));
            }
        }
    }
}
int main()
{
    tot = 0;
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b, v;
        scanf("%d%d%d", &a, &b, &v);
        addEdge(a, b, v);
        addEdge(b, a, v);
    }
    int s, t;
    scanf("%d%d", &s, &t);
    Dijkstra(s);
    printf("%d %d\n", dist[t][0], dist[t][1]);
    return 0;
}
