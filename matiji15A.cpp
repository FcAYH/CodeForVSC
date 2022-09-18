#include <bits/stdc++.h>
using namespace std;
const int MAX = 100010;
int n, m, u, v, del[MAX];
int du[MAX][2]; //记录入度和出度
vector<int> G[MAX];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d", &u, &v), G[u].push_back(v), du[u][1]++, du[v][0]++;
    for (int i = 1; i <= n; i++)
        sort(G[i].begin(), G[i].end());
    int S = 1, cnt[2] = {0, 0}; //记录
    bool flag = 1;              // flag=1表示,所有的节点的入度都等于出度,
    for (int i = 1; i <= n; i++)
    {
        if (du[i][1] != du[i][0])
            flag = 0;
        if (du[i][1] - du[i][0] == 1 /*出度比入度多1*/)
            cnt[1]++, S = i;
        if (du[i][0] - du[i][1] == 1 /*入度比出度多1*/)
            cnt[0]++;
    }
    if ((!flag) && !(cnt[0] == cnt[1] && cnt[0] == 1))
        return !printf("No");
    //不满足欧拉回路的判定条件，也不满足欧拉路径的判定条件，直接输出"No"
    printf("Yes");

    return 0;
}
