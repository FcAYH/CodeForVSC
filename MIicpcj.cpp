#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = 1000000007;
const int Maxn = 1000010;
inline int read()
{
    int fl = 1, rt = 0;
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
ll p, q;
ll Exgcd(ll px, ll py)
{
    if (py == 0)
    {
        p = 1ll, q = 0ll;
        return px;
    }
    ll Gcd = Exgcd(py, px % py), t;
    t = p;
    p = q;
    q = t - (px / py) * q;
    return Gcd;
}
inline ll Quick_Pow(ll a, ll b)
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
    t = read();
    while (t--)
    {
        n = read(), m = read(), a = read(), b = read();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                Map[i][j] = read();
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
