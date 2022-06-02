#include <bits/stdc++.h>

using namespace std;

const int MaxN = 205;
int n, m, k;
bool c[MaxN][MaxN];
char x;
int a[MaxN][MaxN];
int dy[MaxN][MaxN << 1], dn[MaxN][MaxN << 1], dpn[MaxN][MaxN << 1], dpy[MaxN][MaxN << 1];

void Solve()
{
    scanf("%d %d %d\n", &n, &m, &k);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j] >> x;
            if (x == 'Y')
                c[i][j] = 1;
        }
    }

    for (int j = 1; j <= m; j++)
    {
        int tot = 0;
        for (int i = n; i >= 1; i--)
        {
            if (c[i][j] == 1)
                dy[j][tot] += a[i][j];
            else
            {
                tot++;
                dn[j][tot] = dy[j][tot - 1] + a[i][j];
                dy[j][tot] = dn[j][tot];
            }
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int l = 0; l <= min(j, n); l++)
            {
                dpy[i][j] = max(dpy[i][j], dpy[i - 1][j - l] + dy[i][l]);
                if (l != 0)
                    dpn[i][j] = max(dpn[i][j], dpy[i - 1][j - l] + dn[i][l]);
                if (j != l)
                    dpn[i][j] = max(dpn[i][j], dpn[i - 1][j - l] + dy[i][l]);
            }
        }
    }

    printf("%d", dpn[m][k]);
}

int main()
{
    Solve();

    return 0;
}
