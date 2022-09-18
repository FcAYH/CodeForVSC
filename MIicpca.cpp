#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = 1000000007;
const int Inf = 10000001;
const int Maxn = 20000001;
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

int exi[Maxn];
int vis[Maxn];
int a[200011];
int Ans = 0;

inline int Make_Ans(int x)
{
    //printf("%d\n", x);
    if (vis[x])
        return vis[x];
    vis[x] = exi[x];

    int cnt = exi[x];
    int ret = cnt;
    int Nowv = x;
    int k = sqrt(x);

    for (int i = 2; i <= k; i++)
    {
        if (!(x % i))
        {
            int cnt1 = 0, cnt2 = 0;
            if (exi[x / i])
                cnt1 = Make_Ans(x / i);
            if (exi[i])
                cnt2 = Make_Ans(i);
            cnt = max(cnt, ret + max(cnt1, cnt2));
        }
    }
    vis[x] = cnt;

    return cnt;
}

inline int cmp(int x, int y)
{
    return x > y;
}

void Solve()
{
    int n;
    n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        exi[a[i]]++;
    }
    sort(a + 1, a + 1 + n, cmp);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[a[i]])
            Ans = max(Ans, Make_Ans(a[i]));
    }
    printf("%d\n", Ans + exi[1]);
}
int main()
{
    freopen("data.in", "r", stdin);
    freopen("MIicpca.out", "w", stdout);
    Solve();
    //system("pause");
    return 0;
}
/*
6
1 4 2 8 5 7

6
1 1 1 2 2 2

6
100 100000 1000000 1000000 10000000 10000000

9
1 9 72 504 3024 15120 60480 181440  362880

5
2 3 7 1 9 

6
2 2 4 4 4 4

11
1 2 4 8 16 32 64 128 256 512 1024
*/
