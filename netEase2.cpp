#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MaxN = 100010;

ll a[MaxN];

void Solve()
{
    int n, p, x;
    scanf("%d%d%d", &n, &p, &x);

    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        sum += a[i];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll remain = (sum - a[i]) % x;
        ll count = p / x;

        if (p % x >= remain && remain != 0)
            count++;

        if (a[i] <= p && a[i] % x == (x - remain) % x)
            count--;

        // printf("(%d, %d)\n", remain, count);

        ans += count;
    }

    printf("%lld\n", ans);
}

int main()
{
    Solve();

    return 0;
}
