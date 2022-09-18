#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MaxMN = 92;

ll dp[MaxMN];

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);

    dp[1] = 1ll, dp[2] = 2ll;
    for (int i = 3; i <= m * (n - 1); i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    printf("%lld", dp[m * (n - 1)]);

    return 0;
}
