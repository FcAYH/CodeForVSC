#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
const int maxn = 1001;

int vis[maxn];
// 记录结果
double area = 0.0;
struct node
{
    int x;
    int y;
} a[maxn];
bool cmp(node a, node b)
{
    if (a.x != b.x)
    {
        return a.x < b.x;
    }
    return a.y < b.y;
}

// 根据叉乘判断方向
// 判断ac向量在ab向量的顺时针方向还是逆时针方向
// 返回 true表示逆时针方向
// 返回 false表示顺时针方向
bool direction(node a, node b, node c)
{
    // ab向量的坐标
    int x1 = b.x - a.x;
    int y1 = b.y - a.x;
    // ac向量的坐标
    int x2 = c.x - a.x;
    int y2 = c.y - a.y;
    if (x1 * y2 - y1 * x2 > 0)
        return true;
    return false;
}

/*
    求任意三个点连线围成的三角形的面积
*/
double getArea(node a, node b, node c)
{
    // 根据行列式的性质可知，三角形的面积等于三阶行列式的一半
    return fabs(0.5 * (a.x * b.y + b.x * c.y + c.x * a.y - a.x * c.y - b.x * a.y - c.x * b.y));
}
/*
    计算上下凸包的面积，当flag=true,求凸包上半部分的面积
                        当flag=false，求凸包下半部分的面积
    left, right 分别表示凸包区间的左右端点的横坐标，利用分治法进一步求其
    整个凸包的面积
*/
void caculate(bool flag, int left, int right)
{
    /*
        循环遍历的left，right之间的每个点，在left和right指定的一侧时
        并且求其最大面积
    */
    double temp = -1.0;
    int k = 0; // 记录面积最大的那个点的横坐标
    for (int i = left + 1; i <= right - 1; i++)
    {
        // 判断当上下凸包时，该点是否在left和right连线指定的一侧，如果没在就不考虑该点
        if (direction(a[left], a[right], a[i]) != flag)
        {
            continue;
        }
        if (temp < getArea(a[left], a[right], a[i]))
        {
            temp = getArea(a[left], a[right], a[i]);
            k = i;
        }
    }
    // 当k没有改变证明此时只有两个点不构成三角形，故结束递归
    if (k == 0)
        return;
    vis[k] = 1;
    area += temp;
    caculate(flag, left, k);
    caculate(flag, k, right);
}
int main()
{
    area = 0.0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    sort(a + 1, a + n + 1, cmp);
    // 求上凸包的面积
    vis[1] = 1, vis[n] = 1;
    caculate(true, 1, n);
    // 求下凸包的面积
    caculate(false, 1, n);
    cout << fixed << setprecision(1);
    cout << area << endl;

    for (int i = 1; i <= n; i++)
        if (vis[i])
            printf("%d ", i);

    return 0;
}
/*
5
0 0
1 0
0 1
1 1
2 1
*/
