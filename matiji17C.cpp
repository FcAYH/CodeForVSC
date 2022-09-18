#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
struct Seg_Tree
{
    ll l;
    ll r;
    ll v;
};
struct Seg_Tree T[800001 * 4];
ll sl[800001];
ll v[800001 * 4];
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
void clean(ll poi)
{
    if (!v[poi])
        return;
    else
    {
        T[poi].v += (T[poi].r - T[poi].l + 1) * v[poi];
        v[poi << 1] += v[poi];
        v[poi << 1 | 1] += v[poi];
    }
    v[poi] = 0;
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
    T[poi].v = T[poi << 1].v + T[poi << 1 | 1].v;
}
void insert(ll f, ll ne, ll val, ll poi)
{
    if (T[poi].l == f && T[poi].r == ne)
    {
        v[poi] += val;
        return;
    }
    T[poi].v += (min(ne, T[poi].r) - max(f, T[poi].l) + 1) * val;
    ll mid = (T[poi].l + T[poi].r) >> 1;
    if (f > mid)
        insert(f, ne, val, poi << 1 | 1);
    else if (ne <= mid)
        insert(f, ne, val, poi << 1);
    else
    {
        insert(f, mid, val, poi << 1);
        insert(mid + 1, ne, val, poi << 1 | 1);
    }
}
void search(ll f, ll ne, ll poi)
{
    clean(poi);
    if (T[poi].l >= f && T[poi].r <= ne)
    {
        ans += T[poi].v;
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
int main()
{
    n = read();
    m = read();
    for (register int i = 1; i <= n; i++)
    {
        sl[i] = read();
    }
    buildtree(1, n, 1);
    ll si, x, y;
    ll k;
    for (register int i = 1; i <= m; i++)
    {
        si = read();
        if (si == 1ll)
        {
            x = read();
            y = read();
            k = read();
            insert(x, y, k, 1);
        }
        if (si == 2ll)
        {
            ans = 0;
            x = read();
            y = read();
            search(x, y, 1);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
