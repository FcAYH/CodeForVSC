#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Mod = 1e9 + 7ll;
const int MAXN = 2e5;

ll fac[MAXN + 1];

ll QuickPow(ll a, ll b)
{
    ll ret = 1;
    while (b)
    {
        if (b & 1)
            ret = ret * a;
        a = a * a;
        ret %= Mod;
        a %= Mod;
        b >>= 1;
    }

    return ret;
}

void init()
{
    fac[0] = 1ll;
    for (ll i = 1; i <= MAXN; i++)
    {
        fac[i] = (fac[i - 1] * i) % Mod;
    }
}

ll C(int x, int y)
{
    ll ans = (fac[x] * QuickPow(fac[y], Mod - 2) % Mod * QuickPow(fac[x - y], Mod - 2) % Mod) % Mod;
    return ans;
}

void Solve()
{
    init();

    ll n, c;
    scanf("%lld%lld", &n, &c);

    // n!
    ll ans = fac[n];

    //  3!
    ans *= QuickPow(6ll, n);
    ans %= Mod;

    // C(c - 3n, n + 1)

    ans *= C(c - 2 * n - 2, c - 3 * n - 1);
    ans %= Mod;

    ans *= fac[c - 3 * n];
    ans %= Mod;

    // ll ans = fac[c - 2 * n];

    // ans *= QuickPow(6ll, n);
    // ans %= Mod;

    // ans *= QuickPow(fac[c - 3 * n], Mod - 2);
    // ans %= Mod;

    printf("%lld", ans);
}

int main()
{
    Solve();

    return 0;
}
