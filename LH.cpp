#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m, tp, ans = 0;
struct edge //结构体记录每一段的起点、终点
{
    int l;
    int r;
};
struct edge E[100011];
int cmp(edge a, edge b) //排序（按起点从小到大）
{
    return a.l < b.l;
}
void work()
{
    E[0].r = -0x3f3f3f3f; //这个赋值要比最小的起点小就行
    int la = 0;           //记录上一次所铺的是哪一段
    for (int i = 1; i <= n; i++)
    {
        if (E[i].r <= E[la].r + tp)    // tp记录在铺上一段时额外铺的长度
            continue;                  //如果现在要铺的那一段被上一段包含，就可以跳过了，因为已经铺好了
        while (E[i].l <= E[la].r + tp) //如果这次铺的背上一次部分包含
        {
            E[i].l++; //就只铺剩下的，这里可以O（1）解决的，只不过我智障就写了个while
        }
        la = i; //记录一下这次铺的是第几段
        //下面就是计算会超出多少和该段需多少木板了
        if (((E[i].r - E[i].l + 1) % m) == 0)
            tp = 0;
        else
            tp = m - ((E[i].r - E[i].l + 1) % m);
        if (tp == 0)
            ans += (E[i].r - E[i].l + 1) / m;
        else
            ans += (E[i].r - E[i].l + 1) / m + 1;
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &E[i].l, &E[i].r);
        E[i].r--;
    }
    sort(E + 1, E + 1 + n, cmp);
    work();
    printf("%d", ans);
    return 0;
}
