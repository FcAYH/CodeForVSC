#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MaxN = 1000001;

ll Inv[MaxN];
ll p;

void ini()
{
    Inv[1] = 1ll;
    for (int i = 2; i < MaxN; i++)
        Inv[i] = p - (p / i) * Inv[p % i] % p;
}

ll C(int m, int n)
{
    if (m < n - m)
        m = n - m;
    ll ans = 1;
    for (int i = m + 1; i <= n; i++)
        ans *= i, ans %= p;
    for (int i = 1; i <= n - m; i++)
        ans *= Inv[i], ans %= p;
    return ans;
}

int main()
{
    ll m, n;
    scanf("%lld%lld%lld", &m, &n, &p);
    ini();
    printf("%lld\n", C(n, m));
    return 0;
}
