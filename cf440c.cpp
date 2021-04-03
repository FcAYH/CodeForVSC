#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
ll A[30];
ll n;
inline ll read()
{
    ll fl = 1ll, rt = 0ll;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            fl = -1ll;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        rt = rt * 10ll + ch - '0';
        ch = getchar();
    }
    return fl * rt;
}
int Get_n(ll x)
{
    int ret = 0ll;
    while (x != 0)
    {
        x /= 10;
        ret++;
    }
    return ret;
}
ll dfs(ll x, ll dig)
{
    ll use = x / A[dig];
    x = x % A[dig];
    if (x == 0)
        return dig * use;
    else
        return dig * use + min(dig + dfs(A[dig] - x, dig - 1), dfs(x, dig - 1));
}
int main()
{
    for (int i = 1; i <= 17; i++)
        A[i] = A[i - 1] * 10ll + 1ll;
    n = read();
    int Q = Get_n(n);
    printf("%I64d\n", dfs(n, Q + 2ll));
    return 0;
}
