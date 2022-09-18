#include <bits/stdc++.h>

using namespace std;

const int MaxN = 60;

int A[MaxN][MaxN];
int B[MaxN][MaxN];

void Solve()
{
    int n, m, k;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);
    }

    scanf("%d", &k);

    while (k--)
    {
        // 转移
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j == m - 1)
                {
                    if (i == n - 1)
                        B[0][0] = A[i][j];
                    else
                        B[i + 1][0] = A[i][j];
                }
                else
                    B[i][j + 1] = A[i][j];
            }
        }

        // 赋值
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                A[i][j] = B[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", A[i][j]);
        puts("");
    }
}

int main()
{
    Solve();

    return 0;
}
