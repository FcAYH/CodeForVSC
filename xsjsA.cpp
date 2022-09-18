#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Mod = 1e9 + 7;

void Solve()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        ll n, a, b;
        scanf("%lld%lld%lld", &n, &a, &b);

        if (a + b > n)
            printf("0\n");
        else
        {
            ll first = (n - a - b) % Mod;
            ll second = (first + 1) % Mod * (first + 2) % Mod;
            ll ans = second * (((n - a + 1) * 2) % Mod * (n - b + 1) % Mod - second + Mod) % Mod;
            printf("%lld\n", ans);
        }
    }
}

int main()
{
    Solve();

    return 0;
}
