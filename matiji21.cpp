#include <bits/stdc++.h>

using namespace std;

const int MaxN = 2510;

int a[MaxN];
int b[MaxN];

void Solve()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (b[i] == a[j])
                ans = max(ans, j - i);
        }
    }

    printf("%d", ans + 1);
}

int main()
{
    Solve();

    return 0;
}
