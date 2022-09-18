#include <bits/stdc++.h>

using namespace std;

#define Max 110

int n1, n2, m, t;
int match[Max][Max], f[Max][Max], g[Max][Max];
int s1[Max], s2[Max];

int max(int a, int b)
{
    return a > b ? a : b;
}

void Solve()
{
    freopen("1.in", "r", stdin);
    freopen("Altest2_4.out", "w", stdout);

    clock_t start = clock();
    int i, j, k;
    int ii, jj;

    scanf("%d", &m);
    while (m)
    {
        m--;
        scanf("%d%d", &n1, &n2);
        for (i = 1; i <= n1; i++)
            scanf("%d", &s1[i]);
        for (i = 1; i <= n2; i++)
            scanf("%d", &s2[i]);

        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));

        for (i = 1; i <= n1; i++)
        {
            for (j = 1; j <= n2; j++)
            {

                if (s1[i] == s2[j - 1])
                    f[i][j] = j - 1;
                else
                    f[i][j] = f[i][j - 1];
            }
        }

        for (i = 1; i <= n2; i++)
        {
            for (j = 1; j <= n1; j++)
            {
                if (s2[i] == s1[j - 1])
                    g[i][j] = j - 1;
                else
                    g[i][j] = g[i][j - 1];
            }
        }

        memset(match, 0, sizeof(match));

        for (i = 1; i <= n1; i++)
        {
            for (j = 1; j <= n2; j++)
            {
                match[i][j] = max(match[i - 1][j], match[i][j - 1]);

                if (s1[i] == s2[j])
                    continue;

                ii = f[i][j], jj = g[j][i];
                if (ii == 0 || jj == 0)
                    continue;

                match[i][j] = max(match[i][j], match[jj - 1][ii - 1] + 2);
            }
        }
        //printf("%d\n", match[n1][n2]);
    }
    clock_t end = clock();

    printf("%d", end - start);
}

int main()
{
    Solve();

    return 0;
}
