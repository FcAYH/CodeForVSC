#include <bits/stdc++.h>

using namespace std;

const int MaxN = 5e6 + 10;

int a[MaxN];
int b[MaxN];

void Solve()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    int l, r, v;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &l, &r, &v);
        b[l] += v;
        b[r + 1] -= v;
    }

    int ans = 0x3f3f3f3f;
    int plus = 0;
    for (int i = 1; i <= n; i++)
    {
        plus += b[i];
        ans = min(ans, a[i] + plus);
    }

    printf("%d", ans);
}

int main()
{
    Solve();

    return 0;
}

/*
3 2
1 1 1
1 2 1
2 3 1

1     1     1
1          -1
      1           -1
2     3     2
*/
