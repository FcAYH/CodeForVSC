#include <bits/stdc++.h>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

using namespace std;

long long z[1000005 << 2 | 1], sum[1000005 << 2 | 1], add[1000005 << 2 | 1], mul[1000005 << 2 | 1];
long long n, m, a, p = 100000ll;

void update(int rt)
{
    sum[rt] = (sum[rt << 1] + sum[rt << 1 | 1]) % p;
    return;
}

void color(int l, int r, int rt, int x, int y)
{
    sum[rt] = ((sum[rt] * y) + (1ll * (r - l + 1) * x)) % p;
    mul[rt] = (mul[rt] * y) % p;
    add[rt] = (add[rt] * y + x) % p;
    return;
}

void push_col(int l, int r, int rt)
{
    if (mul[rt] != 1 || add[rt] != 0)
    {
        int m = (l + r) >> 1;
        color(lson, add[rt], mul[rt]);
        color(rson, add[rt], mul[rt]);
        add[rt] = 0;
        mul[rt] = 1;
    }
    return;
}

void build(int l, int r, int rt)
{
    mul[rt] = 1;
    add[rt] = 0;
    if (l == r)
    {
        sum[rt] = z[l];
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    update(rt);
}

void modify(int l, int r, int rt, int nowl, int nowr, int x, int y)
{
    if (nowl <= l && r <= nowr)
    {
        color(l, r, rt, x, y);
        return;
    }
    if (mul[rt] != 1 || add[rt] != 0)
        push_col(l, r, rt);
    int m = (l + r) >> 1;
    if (nowl <= m)
        modify(lson, nowl, nowr, x, y);
    if (m < nowr)
        modify(rson, nowl, nowr, x, y);
    update(rt);
}

long long query(int l, int r, int rt, int nowl, int nowr)
{
    if (nowl <= l && r <= nowr)
    {
        return (sum[rt]) % p;
    }
    if (mul[rt] != 1 || add[rt] != 0)
        push_col(l, r, rt);
    int m = (l + r) >> 1;
    long long ans = 0;
    if (nowl <= m)
        ans += query(lson, nowl, nowr) % p;
    if (m < nowr)
        ans += query(rson, nowl, nowr) % p;
    return ans % p;
}

void Solve()
{
    long long x, y, k;
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &z[i]);
    }
    build(1, n, 1);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld %lld %lld", &x, &y, &k);
        modify(1, n, 1, x, y, 0, k);
    }

    for (int i = 1; i <= n; i++)
    {
        printf("%lld ", query(1, n, 1, i, i) % p);
    }
}

int main()
{
    Solve();

    return 0;
}
