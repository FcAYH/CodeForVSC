#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 200010;
int n, m, root[MAXN], cut, a[MAXN], s[MAXN];
struct data
{
    int lc, rc, ans;
} tree[MAXN * 20];
void add(int &now, int last, int l, int r, int x)
{
    now = ++cut;
    tree[now].ans = tree[last].ans + 1;

    if (l == r)
        return;
    tree[now].lc = tree[last].lc;
    tree[now].rc = tree[last].rc;
    int mid = (l + r) >> 1;
    if (x <= mid)
        add(tree[now].lc, tree[last].lc, l, mid, x);
    else
        add(tree[now].rc, tree[last].rc, mid + 1, r, x);
}
int query(int L, int R, int l, int r, int x)
{
    if (l == r)
        return tree[L].ans - tree[R].ans;
    int mid = (l + r) >> 1;
    if (x <= mid)
        return query(tree[L].lc, tree[R].lc, l, mid, x);
    else
        return query(tree[L].rc, tree[R].rc, mid + 1, r, x);
}
int main()
{
    int x, y, z, p = 0;
    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        p = max(p, a[i]);
    }
    for (int i = 1; i <= n; ++i)
        add(root[i], root[i - 1], 1, p, a[i]);

    while (m--)
    {
        scanf("%d%d%d", &x, &y, &z);
        if (z > p)
        {
            printf("0\n");
            continue;
        }
        printf("%d\n", query(root[y], root[x - 1], 1, p, z));
    }
    return 0;
}
