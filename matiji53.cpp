#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MaxM = 100010;

struct Seg_Tree
{
    ll l;
    ll r;
    ll v;
};
struct Seg_Tree T[MaxM * 4];
ll sl[MaxM];
ll v[MaxM * 4];
ll n, m;
ll ans = 0ll;
ll read()
{
    ll fl = 1ll, rt = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            fl = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        rt = rt * 10ll + ch - '0';
        ch = getchar();
    }
    return fl * rt;
}

void buildtree(ll f, ll ne, ll poi)
{
    T[poi].l = f;
    T[poi].r = ne;
    if (f == ne)
    {
        T[poi].v = sl[f];
        return;
    }
    ll mid = (T[poi].l + T[poi].r) >> 1;
    buildtree(f, mid, poi << 1);
    buildtree(mid + 1, ne, poi << 1 | 1);
    T[poi].v = min(T[poi << 1].v, T[poi << 1 | 1].v);
}

void search(ll f, ll ne, ll poi)
{
    if (T[poi].l >= f && T[poi].r <= ne)
    {
        ans = min(ans, T[poi].v);
        return;
    }

    ll mid = (T[poi].r + T[poi].l) >> 1;
    if (f > mid)
        search(f, ne, poi << 1 | 1);
    else if (ne <= mid)
        search(f, ne, poi << 1);
    else
    {
        search(f, mid, poi << 1);
        search(mid + 1, ne, poi << 1 | 1);
    }
}

void Solve()
{
    m = read();
    n = read();
    for (int i = 1; i <= m; i++)
    {
        sl[i] = read();
    }
    buildtree(1, n, 1);

    for (int i = 1; i <= n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);

        ans = INF;
        search(l, r, 1);
        printf("%d ", ans);
    }
}

int main()
{
    Solve();

    return 0;
}
