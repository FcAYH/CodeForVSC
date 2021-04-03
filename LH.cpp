#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <queue>
#include <ctime>
#include <set>
#include <vector>
#include <iomanip>
#include <cassert>
using namespace std;
int n, ans;
long long f[202020];
int vis[10100000];
int rec[10100000];
int read()
{
    int rt = 0, in = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            in = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        rt = rt * 10 + ch - '0';
        ch = getchar();
    }
    return rt * in;
}
int dfs(int x, int tot)
{
    if (rec[x])
        return rec[x];
    rec[x] = vis[x];
    int k = sqrt(x);
    for (int i = 2; i <= k; i++)
        if (x % i == 0)
        {
            int l = x / i;
            if (vis[i])
                rec[x] = max(tot + dfs(i, tot + vis[i]), rec[x]);
            if (vis[l])
                rec[x] = max(tot + dfs(l, tot + vis[l]), rec[x]);
        }
    return rec[x];
}
int main()
{
    freopen("data.in", "r", stdin);
    freopen("LH.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; i++)
    {
        f[i] = read();
        vis[f[i]]++;
    }
    sort(f + 1, f + 1 + n);
    for (int i = 1; i <= n; i++)
        rec[f[i]] = dfs(f[i], vis[f[i]]);
    for (int i = 1; i <= n; i++)
        ans = max(rec[f[i]], ans);
    cout << ans + vis[1] << endl;
    //system("pause");
    return 0;
}
