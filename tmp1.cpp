#include <bits/stdc++.h>

using namespace std;

// 结构定义
typedef struct p
{
    int x, y;
} p;

bool cmp(const p &p1, const p &p2)
{
    if (p1.x == p2.x)
        return p1.y < p2.y;
    return p1.x < p2.x;
}

// 存放点
p points[100];
int vis[100];

// 计算p1,p2,pi三个点组成的三角形面积
int peak(p p1, p p2, p pi)
{
    return p1.x * p2.y + pi.x * p1.y + p2.x * pi.y - pi.x * p2.y - p2.x * p1.y - p1.x * pi.y;
}

// 递归求凸包
// ps 是当前要求解的点的集合，ps保存这些点在points数组中的下标
// mode 表示递归s1 s2，还是递归s3，s4，还是同时递归 s1，s2，s3，s4
// mode = 3 递归 s1，s2，s3，s4，只有第一次调用会出现该情况
// mode = 2 递归s3，s4
// mode = 1 递归s1 s2
void hull(vector<int> &ps, int mode)
{
    // 边界处理：少于两个点的集合一定是凸包上的点
    if (ps.size() <= 2)
    {
        for (int i = 0; i < ps.size(); i++)
            vis[ps[i]] = 1;
        return;
    }

    // 最左右一定是凸包上的点， pa最左点，pb最右点
    vis[ps.front()] = 1, vis[ps.back()] = 1;
    p pa = points[ps.front()], pb = points[ps.back()];

    // 找距离 pa，pb组成的直线最远的点，imax是上方最远，imin是下方最远
    int maxs = INT_MIN, mins = INT_MAX, imax = -1, imin = -1;
    for (int i = 1; i < ps.size() - 1; i++)
    {
        int s = peak(pa, pb, points[ps[i]]);
        if (s > maxs && s >= 0)
            maxs = s, imax = ps[i];
        if (s < mins && s <= 0)
            mins = s, imin = ps[i];
    }

    // pa,pb与imax，imin的连线，分割出下一趟递归的点集合 s1 s2 s3 s4
    vector<int> s1, s2, s3, s4;
    for (int i = 0; i < ps.size() - 1; i++)
    {
        if (peak(pa, points[imax], points[ps[i]]) >= 0)
            s1.push_back(ps[i]);
        if (peak(pa, points[imin], points[ps[i]]) <= 0)
            s3.push_back(ps[i]);
    }
    for (int i = 1; i < ps.size(); i++)
    {
        if (peak(points[imax], pb, points[ps[i]]) >= 0)
            s2.push_back(ps[i]);
        if (peak(points[imin], pb, points[ps[i]]) <= 0)
            s4.push_back(ps[i]);
    }

    if (mode == 3)
        hull(s1, 1), hull(s2, 1), hull(s3, 2), hull(s4, 2);
    else if (mode == 1)
        hull(s1, 1), hull(s2, 1);
    else if (mode == 2)
        hull(s3, 2), hull(s4, 2);
}

int main()
{

    int n, x, y;
    cin >> n;
    vector<int> ps(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y, ps[i] = i;
    sort(points, points + n, cmp);

    hull(ps, 3);

    for (int i = 0; i < n; i++)
        if (vis[i] == 1)
            cout << "(" << points[i].x << ", " << points[i].y << ")" << endl;

    return 0;
}
