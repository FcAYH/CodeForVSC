#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MaxN = 100010;
const ll Mod = 1e9 + 7;

ll dp[MaxN][3][3];

void Solve()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(dp, 0, sizeof(dp));

        int n;
        scanf("%d", &n);

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                dp[1][i][j] = 1;

        for (int i = 2; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (j != k)
                    {
                        for (int l = 0; l < 3; l++)
                        {
                            dp[i][j][k] += dp[i - 1][k][l];
                            dp[i][j][k] %= Mod;
                        }
                    }
                    else
                    {
                        for (int l = 0; l < 3; l++)
                        {
                            if (l == k)
                                continue;
                            dp[i][j][k] += dp[i - 1][k][l];
                            dp[i][j][k] %= Mod;
                        }
                    }
                }
            }
        }

        ll ans = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                ans += dp[n - 1][i][j];
                ans %= Mod;
            }
        }
        printf("%lld\n", ans);
    }
}

int main()
{
    Solve();

    return 0;
}
