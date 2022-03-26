#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

const unsigned __int128 Mod = 998244353;

void print(unsigned __int128 n)
{
    if (n < 0)
    {
        putchar('-');
        n *= -1;
    }
    if (n > 9)
        print(n / 10);
    putchar(n % 10 + '0');
}

int main()
{
    ll in, ik;
    scanf("%lld", &in);
    ik = in;
    unsigned __int128 n = in, k = ik;
    unsigned __int128 ans = in * ik;
    // printf("%lf", ans);
    for (unsigned __int128 l = 1, r; l <= n; l = r + 1)
    {
        if (k / l != 0)
            r = min(k / (k / l), n);
        else
            r = n;
        ans -= (k / l) * (r - l + 1) * (l + r) / 2;
    }
    ans %= Mod;
    print(ans);
    return 0;
}
