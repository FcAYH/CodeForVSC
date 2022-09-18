#include <bits/stdc++.h>

using namespace std;

const int MaxN = 100010;

double x1[MaxN], Y1[MaxN];

void Solve()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%lf%lf", &x1[i], &Y1[i]);
    }

    double ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans += sqrt((x1[i] - x1[i - 1]) * (x1[i] - x1[i - 1]) + (Y1[i] - Y1[i - 1]) * (Y1[i] - Y1[i - 1]));
    }
    ans += sqrt((x1[0] - x1[n - 1]) * (x1[0] - x1[n - 1]) + (Y1[0] - Y1[n - 1]) * (Y1[0] - Y1[n - 1]));

    printf("%.2lf", ans);
}

int main()
{
    Solve();

    return 0;
}
