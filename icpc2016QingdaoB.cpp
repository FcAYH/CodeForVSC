#include "bits/stdc++.h"
using namespace std;
double p[15];
double sum[15][30];
double ssum[15][30];
double a[15][30];
int num[15];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", num + i);
            scanf("%lf", p + i);
            p[i] = 1 - p[i];
        }
        if (n == 1)
        {
            printf("1.000000\n");
            continue;
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 30; j++)
            {
                if (j == 0)
                    a[i][j] = 1;
                else
                    a[i][j] = a[i][j - 1] * p[i];
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 30; j++)
            {
                a[i][j] = 1 - a[i][j];
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 30; j++)
            {
                sum[i][j] = pow(a[i][j], num[i]);
            }
        double ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                ssum[i][j] = 1;
                for (int k = 0; k < n; k++)
                    if (k != i)
                    {
                        ssum[i][j] *= sum[k][j];
                    }
                ssum[i][j] = 1 - ssum[i][j];
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 5; j++)
                printf("%lf%c", sum[i][j], " \n"[j == 4]);
        for (int i = 0; i < n; i++)
        {
            ans = 0;
            for (int j = 1; j < 30; j++)
            {
                if (ssum[i][j - 1] == 0)
                    break;
                ans += (1 - ssum[i][j] / ssum[i][j - 1]) * (1 - sum[i][j]);
            }
            printf("%lf%c", ans, " \n"[i == n - 1]);
        }
    }
    return 0;
}
