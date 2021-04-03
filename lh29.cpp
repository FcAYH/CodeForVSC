#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1001;
const int Mod = 1000000007;
int n, m, k;
int A[Maxn], B[Maxn];
int dp[Maxn][Maxn][11];

void Dynamic_P()
{
    // for (int i = 0; i <= n; i++)
    //     dp[i][0][0] = 1;
    // for (int i = 0; i <= m; i++)
    //     dp[0][i][0] = 1;

    for (int w = 1; w <= k; w++)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                dp[i][j][w] = dp[i - 1][j][w] + dp[i][j - 1][w] - dp[i - 1][j - 1][w];
                if (A[i] == B[j])
                {
                    if (w != 1)
                        if (dp[i - 1][j - 1][w - 1])
                            dp[i][j][w] = dp[i - 1][j - 1][w - 1] + 1;
                        else
                            dp[i][j][w] = dp[i - 1][j - 1][w - 1] + 1;
                }
                dp[i][j][w] = (dp[i][j][w] + Mod) % Mod;
            }
    }
}

void Solve()
{
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &B[i]);

    Dynamic_P();
    // for (int i = 1; i <= n; i++)
    //     for (int j = 1; j <= n; j++)
    //         printf("%d ", dp[i][j][k]);
    printf("%d\n", dp[3][2][2]);
    printf("%d", dp[n][m][k]);
}

int main()
{
    Solve();

    return 0;
}

/*
5 4 2
3 2 7 6 7
2 3 5 7
*/
