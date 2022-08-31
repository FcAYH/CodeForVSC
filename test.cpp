/*
为什么没有k的范围？
*/
#include <bits/stdc++.h>

using namespace std;

const int MaxN = 20010;
const int MaxK = 100;

int dp[MaxN][MaxK];
int n, k;
int tree[MaxN];

void dfs(int poi)
{
    printf("%d", poi);
    if ((poi << 1) <= n && tree[poi << 1] != -1)
    {
        dfs(poi << 1);
    }

    if ((poi << 1 | 1) <= n && tree[poi << 1 | 1] != -1)
    {
        dfs(poi << 1 | 1);
    }

    // poi 不开采
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[poi][0] = max(dp[poi][0], dp[poi << 1][i] + dp[poi << 1 | 1][j]);
        }
    }

    // poi 开采
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int rLink = i - j - 1;
            dp[poi][i] = max(dp[poi][i], dp[poi << 1][j] + dp[poi << 1 | 1][rLink] + tree[poi]);
        }
    }
}

void Solve()
{
    scanf("%d%d", &k, &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &tree[i]);

    dfs(0);

    int ans = 0;
    for (int i = 0; i <= k; i++)
    {
        ans = max(ans, dp[0][i]);
    }
    printf("%d", ans);
}

int main()
{
    Solve();

    return 0;
}
