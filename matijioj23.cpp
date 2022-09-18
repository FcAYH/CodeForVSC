#include <bits/stdc++.h>

using namespace std;

const int MaxN = 100001;

int a[MaxN];
int vis[MaxN];

void Solve()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int count = 0;
    int l = 0, r = 0;
    int ans = 0;
    while (r < n)
    {
        if (!vis[a[r]])
            count++;

        vis[a[r]]++;

        while (count > 2)
        {
            vis[a[l]]--;
            if (vis[a[l]] == 0)
                count--;

            l++;
        }

        ans = max(ans, r - l + 1);
        r++;
    }

    printf("%d", ans);
}

int main()
{
    Solve();

    return 0;
}
