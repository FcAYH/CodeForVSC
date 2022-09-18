#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int scope = 23;
int n, ans = 1 << 30, tot;
int vis[scope], minn[scope];
struct node
{
    int order;
    int v;
} pos[scope][scope];
bool rule(const node &s1, const node &s2)
{
    return s1.v < s2.v;
}
void dfs(int x, int num) //x表示当前所在的点，num表示已经走过了num个点
{
    if (num == n) //如果我们已经走过了n个点，就说明要回一号点了
    {
        if (tot + minn[x] < ans)
            ans = tot + minn[x];
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        if (!vis[pos[x][i].order]) //如果这个点没走过
        {
            //剪枝：
            if (tot + pos[x][i].v >= ans)
                return; //如果我们走这一步走过的距离就比之前的最优解差了，就不要走了
            if (tot + (n - num) + 1 >= ans)
                return;               //即使我们后面要走的路长度都是1，仍然不比最优解好，也不要走了
            vis[pos[x][i].order] = 1; //剩下就是普通的搜索了，tot记录走的长度
            tot += pos[x][i].v;
            dfs(pos[x][i].order, num + 1);
            vis[pos[x][i].order] = 0;
            tot -= pos[x][i].v;
        }
    }
}
int main()
{
    scanf("%d", &n); //稳稳的读入数据
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            scanf("%d", &pos[i][j].v); //因为后面要排序，就分开记录边权和后继
            pos[j][i].v = pos[i][j].v;

            pos[i][j].order = j; //后继
            pos[j][i].order = i;
        }
        minn[i] = pos[i][1].v;                  //记录一下每个点回一号点的路径长度，因为后面要排序，这样可以避免之后要O（n）找回1点的边
        sort(pos[i] + 1, pos[i] + n + 1, rule); //把从每个点出来的边排序，则第一个边肯定是去自己的那一条
    }
    vis[1] = 1;
    dfs(1, 1);
    printf("%d", ans); //输出答案
    return 0;
}
