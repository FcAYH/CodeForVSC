#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
int n,p1,p2,ans;
int f[101010],g[101010],Min[404040],Max[404040];
void build_bigtree(int cur, int l, int r)
{
    if(l == r)
    {
        Max[cur] = f[l];
        return;
    }
    int mid = l + r >> 1;
    build_bigtree(cur<<1, l, mid);
    build_bigtree(cur<<1|1, mid+1, r);
    Max[cur] = max(Max[cur<<1], Max[cur<<1|1]);
    return;
}
void build_smalltree(int cur, int l, int r)
{
    if(l == r)
    {
        Min[cur] = g[l];
        return;
    }
    int mid = l + r >> 1;
    build_smalltree(cur<<1, l, mid);
    build_smalltree(cur<<1|1, mid+1, r);
    Min[cur] = min(Min[cur<<1], Min[cur<<1|1]);
    return;
}
void query_max(int cur, int l, int r, int L, int R)
{
    if(L <= l && r <= R)
    {
        p1 = max(p1, Max[cur]);
        return;
    }
    int mid = l + r >> 1;
    if(R <= mid)    query_max(cur<<1, l, mid, L, R);
    else if(L > mid)    query_max(cur<<1|1, mid+1, r, L, R);
    else    query_max(cur<<1, l, mid, L, mid), query_max(cur<<1|1, mid+1, r, mid+1, R);
}
void query_min(int cur, int l, int r, int L, int R)
{
    if(L <= l && r <= R)
    {
        p2 = min(p2, Min[cur]);
        return;
    }
    int mid = l + r >> 1;
    if(R <= mid)    query_min(cur<<1, l, mid, L, R);
    else if(L > mid)    query_min(cur<<1|1, mid+1, r, L, R);
    else    query_min(cur<<1, l, mid, L, mid), query_min(cur<<1|1, mid+1, r, mid+1, R);
}
int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%d%d",&f[i],&g[i]);
    build_bigtree(1, 1, n), build_smalltree(1, 1, n);
    int L = 1, R = 1;
    while(L <= R && R <= n)
    {
        p1 = 0, p2 = 1e9;
        query_max(1, 1, n, L, R);
        query_min(1, 1, n, L, R);
        if(p2 - p1 + 1 >= R - L + 1)    ans = max(ans, R - L + 1), R++;
        else    L++;
    }
    printf("%d",ans);
    system("pause");
    return 0;
}
/*
3
1 1
0 2
1 1
*/
/*
8
2 4
2 4
1 4
0 7
0 3
1 2
1 2
1 1
*/