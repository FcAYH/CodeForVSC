
#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;

int f[(1 << maxn) + 1][maxn + 10];
int e[maxn * 5][maxn * 5], n;

int main()
{
    memset(f, 0x3f, sizeof(f));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            scanf("%d", &e[i][j]);
    }
    f[1][1] = 0;
    for (int i = 0; i <= (1 << n) - 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (((1 << (j - 1)) & i) == 0)
                for (int k = 1; k <= n; k++)
                    if ((1 << (k - 1)) & i)
                        f[i | (1 << j - 1)][j] = min(f[i | (1 << j - 1)][j], f[i][k] + e[k][j]);
        }
    }

    int ans = 1e9;
    for (int i = 2; i < n; i++)
        ans = min(ans, f[(1 << n) - 1][i] + e[i][1]);
    printf("%d", ans);

    return 0;
}
