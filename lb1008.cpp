#include <bits/stdc++.h>

using namespace std;

void Solve()
{
    int n, m;
    int a[110];
    int b[110];
    scanf("%d%d", &n, &m);
    m = m % n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n - m; i++)
    {
        b[i + m] = a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        b[i] = a[n - m + i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
            printf("%d", b[i]);
        else
        {
            printf(" %d", b[i]);
        }
    }
}

int main()
{
    Solve();

    return 0;
}
