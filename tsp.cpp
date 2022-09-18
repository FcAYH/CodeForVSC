#include <bits/stdc++.h>

using namespace std;

int f[1 << 20][20], w[20][20], n;

int main()
{
    memset(f, 0x3f, sizeof f);

    f[1][0] = 0;

    cin >> n;

    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
        {
            scanf("%d", &w[i][j]);
            w[j][i] = w[i][j];
        }

    for (int i = 1; i < (1 << n); i += 2)
    {
        for (int j = 0; j < n; j++)
        {
            if (!((i >> j) & 1))
                continue; //当前i状态下，根本没有走过j
            for (int k = 0; k < n; k++)
            {
                if (j == k)
                    continue; //从自己到自己？。。。
                if (!(i >> k & 1))
                    continue; //上一次状态，根本没有走过k，就更不可能从k转移到j
                f[i][j] = min(f[i][j], f[i ^ (1 << j)][k] + w[k][j]);
            }
        }
    }

    int minn = 8848888;

    for (int i = 0; i <= n - 1; ++i)
    {
        minn = min(minn, f[(1 << n) - 1][i] + w[i][0]);
    }

    cout << minn; //所有点走完，最后停在n-1点上

    return 0;
}
//5 4 8 6 5 3 2 10 8 7 3
