#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Mod = 4933;
// const ll Maxn = 1000010;

inline ll read()
{
    ll fl = 1, rt = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            fl = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        rt = rt * 10 + ch - '0';
        ch = getchar();
    }
    return fl * rt;
}

inline ll QuickPow(ll a, ll b)
{
    ll ret = 1;
    while (b > 0)
    {
        if (b & 1)
            ret *= a;
        a *= a, b >>= 1;
        a %= Mod, ret %= Mod;
    }
    return ret;
}

void Solve()
{
    ll n = read(), m = read(), k = read(), a = read(), l = read();

    ll Ans = 1;

    for (ll i = 1; i <= k; i++)
    {
        ll x = read(), y = read(), z = read();

        if (x != 0 && y == z)
        {
            printf("%lld", a % Mod);
            return;
        }

        if (x == 0)
            continue;

        Ans = ((Ans * (z - y)) * QuickPow(z, Mod - 2)) % Mod;
    }

    printf("%lld", (Ans + a) % Mod);
}

int main()
{
    Solve();

    return 0;
}
