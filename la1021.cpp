#include <bits/stdc++.h>

using namespace std;

vector<int> dt[10010];
int vis[10010];

void Solve()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        dt[u].push_back(v);
        dt[v].push_back(u);
    }

    // 1 为根，找最深的
    int maxDepth = 0, target = -1;
    queue<int> q;
    queue<int> depthQ;
    q.push(1);
    depthQ.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        int cur = q.front();
        int curDepth = depthQ.front();

        if (curDepth > maxDepth)
        {
            maxDepth = curDepth;
            target = cur;
        }

        q.pop();
        depthQ.pop();

        for (int i = 0; i < dt[cur].size(); i++)
        {
            int dest = dt[cur][i];
            if (vis[dest] == 1)
                continue;

            q.push(dest);
            depthQ.push(curDepth + 1);
            vis[dest] = 1;
        }
    }

    memset(vis, 0, sizeof(vis));
    // i，以i为根，找最深的
    q.push(target);
    depthQ.push(1);
    vis[target] = 1;
    while (!q.empty())
    {
        int cur = q.front();
        int curDepth = depthQ.front();

        if (curDepth > maxDepth)
            maxDepth = curDepth;

        q.pop();
        depthQ.pop();

        for (int i = 0; i < dt[cur].size(); i++)
        {
            int dest = dt[cur][i];
            if (vis[dest] == 1)
                continue;

            q.push(dest);
            depthQ.push(curDepth + 1);
            vis[dest] = 1;
        }
    }

    printf("%d", maxDepth);
}

int main()
{
    Solve();

    return 0;
}

/*
  3
 / \
2  4
*/
