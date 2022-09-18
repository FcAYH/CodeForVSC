#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = 1000000007;
const int Maxn = 1000010;

int a[Maxn];

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

void Solve()
{
    int T;
    T = read();
    for (int t = 1; t <= T; t++)
    {
        int n = read();
        for (int i = 1; i <= n; i++)
            a[i] = read();
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans ^= max(0, a[i] - 2);
        printf("Case %d: %d\n", t, ans);
    }
}
int main()
{
    Solve();
    return 0;
}