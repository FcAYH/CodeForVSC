#include <iostream>
using namespace std;
#include <algorithm>
#include <stdlib.h>
#define N 10000
int n = 0;
struct POINT
{
    int x, y;
} p[N], ans[N];
int visit[N], mark[N];
int Djudge(POINT a1, POINT a2, POINT a3)
{
    int calculate = a1.x * a2.y + a3.x * a1.y + a2.x * a3.y - a3.x * a2.y - a2.x * a1.y - a1.x * a3.y;
    return calculate;
}
bool cmpxy(const POINT a, const POINT b) //按x轴排序,如果x相同,按y轴排序
{
    if (a.x != b.x)
        return a.x < b.x;
    else
        return a.y < b.y;
}
void DealLeft(int first, int last)
{
    int max = 0, index = -1;
    int i = first;
    if (first < last)
    {
        for (i = first + 1; i < last; i++) //注意两端,对于first和last,没必要再进行计算
        {
            int calcu = Djudge(p[first], p[i], p[last]);
            if (calcu == 0)
            {
                visit[i] = 1;
            } //
            if (calcu > max)
            {
                max = calcu;
                index = i;
            }
        }
    }
    else
    {
        for (i - 1; i > last; i--) //如果first>last,重复上述过程,注意这里下界不是0.
        {
            int calcu = Djudge(p[first], p[i], p[last]);
            if (calcu == 0)
            {
                visit[i] = 1;
            } //
            if (calcu > max)
            {
                max = calcu;
                index = i;
            }
        }
    }
    if (index != -1)
    {
        visit[index] = 1; //对取到的点进行标注
        DealLeft(first, index);
        DealLeft(index, last); //分治的部分
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].x >> p[i].y;
        visit[i] = 0;
    }
    visit[0] = 1;
    visit[n - 1] = 1;
    sort(p, p + n, cmpxy);
    DealLeft(0, n - 1); //查找上凸包;
    DealLeft(n - 1, 0); //查找下凸包;
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        if (visit[i] == 1)
        {
            ans[t].x = p[i].x;
            ans[t].y = p[i].y;
            t++;
        }
    }
    //顺时针输出
    mark[0] = mark[t - 1] = 1; //数组mark避免重复检查降低效率
    for (int i = 1; i < t - 1; i++)
    {
        mark[i] = 0;
    }
    cout << ans[0].x << " " << ans[0].y << endl;
    for (int i = 1; i < t - 1; i++)
    {
        int d = Djudge(ans[0], ans[t - 1], ans[i]);
        if (d >= 0)
        {
            cout << ans[i].x << " " << ans[i].y << endl;
            mark[i] = 1;
        }
    }
    cout << ans[t - 1].x << " " << ans[t - 1].y << endl;
    for (int i = 1; i < t; i++)
    {
        if (mark[i] != 1)
        {
            int d = Djudge(ans[0], ans[t - 1], ans[i]);
            if (d < 0)
            {
                cout << ans[i].x << " " << ans[i].y << endl;
            }
        }
    }

    return 0;
}
