#include <bits/stdc++.h>

using namespace std;

typedef struct p
{
    int x, y;
    p() {}
    p(int X, int Y) : x(X), y(Y) {}
} p;

/*
浮点最小函数，防止默认min的int形参截断 
*/
double lfmin(double a, double b)
{
    return (a < b) ? (a) : (b);
}

/*
比较函数，排序用，x升序，x相同则y升序
param p1 : 第一个点
param p2 : 第二个点 
return   : p1 前于 p2 ? 
*/
bool cmpx(const p &p1, const p &p2)
{
    if (p1.x == p2.x)
        return p1.y < p2.y;
    return p1.x < p2.x;
}

/*
比较函数，排序用，则y升序，归并用 
param p1 : 第一个点
param p2 : 第二个点 
return   : p1 前于 p2 ? 
*/
bool cmpy(const p &p1, const p &p2)
{
    return p1.y < p2.y;
}

/*
求解两点欧氏距离 
param p1 : 第一个点
param p2 : 第二个点 
return   : 距离，浮点数 
*/
double dis(const p &p1, const p &p2)
{
    return sqrt((double)(p1.x - p2.x) * (p1.x - p2.x) + (double)(p1.y - p2.y) * (p1.y - p2.y));
}

/*
求两点水平距离 
param p1 : 第一个点
param p2 : 第二个点 
return   : 水平距离，浮点数 
*/
double disX(const p &p1, const p &p2)
{
    double ans = (double)p1.x - (double)p2.x;
    if (ans < 0)
        return ans * -1;
    return ans;
}

/*
暴力求解最近点对
param points : 点的数组
return       : 最近点对距离 
*/
double cp(vector<p> &points)
{
    double ans = (double)INT_MAX;
    for (int i = 0; i < points.size(); i++)
        for (int j = i + 1; j < points.size(); j++)
            ans = lfmin(ans, dis(points[i], points[j]));
    return ans;
}

/*
分治求解最近点对，复杂度O(nlog(n)log(n)) 
param points : 点的数组
param l      : 点数组左端点
param r      : 点数组右端点 
return       : 最近点对距离 
explain      : 区间[l, r]左闭右闭 
*/
double cp(vector<p> &points, int l, int r)
{
    if (l >= r)
        return (double)INT_MAX;
    if (l + 1 == r)
        return dis(points[l], points[r]);
    int mid = (l + r) / 2, le = mid, ri = mid, h = 0;
    double d = lfmin(cp(points, l, mid), cp(points, mid + 1, r)), ans = d;
    vector<p> ll, rr;
    while (le >= l && disX(points[mid], points[le]) <= d)
        ll.push_back(points[le]), le--;
    while (ri <= r && disX(points[mid], points[ri]) <= d)
        rr.push_back(points[ri]), ri++;
    sort(ll.begin(), ll.end(), cmpy), sort(rr.begin(), rr.end(), cmpy);
    for (int i = 0; i < ll.size(); i++)
    {
        while (h < rr.size() && rr[h].y + d < ll[i].y)
            h++;
        h = min((int)rr.size(), h);
        for (int j = h; j < min((int)rr.size(), h + 6); j++)
            if (!eqfunc()(ll[i], rr[j]))
                ans = lfmin(ans, dis(ll[i], rr[j]));
    }
    return lfmin(ans, d);
}

/*
分治+归并求解最近点对，复杂度O(nlog(n)) 
param points : 点的数组
param l      : 点数组左端点
param r      : 点数组右端点 
return       : 最近点对距离 
explain      : 区间[l, r]左闭右闭 
*/
double cpm(vector<p> &points, int l, int r)
{
    if (l >= r)
        return (double)INT_MAX;
    if (l + 1 == r)
    {
        if (cmpy(points[r], points[l]))
            swap(points[l], points[r]);
        return dis(points[l], points[r]);
    }
    int mid = (l + r) / 2, le = mid, ri = mid, h = 0;
    p midp = points[mid];
    double d = lfmin(cpm(points, l, mid), cpm(points, mid + 1, r)), ans = d;
    inplace_merge(points.begin() + l, points.begin() + mid + 1, points.begin() + r + 1, cmpy);
    vector<p> ll, rr;
    for (int i = l; i <= r; i++)
    {
        if (midp.x >= points[i].x && disX(midp, points[i]) <= d)
            ll.push_back(points[i]);
        if (midp.x <= points[i].x && disX(midp, points[i]) <= d)
            rr.push_back(points[i]);
    }
    for (int i = 0; i < ll.size(); i++)
    {
        while (h < rr.size() && rr[h].y + d < ll[i].y)
            h++;
        h = min((int)rr.size(), h);
        for (int j = h; j < min((int)rr.size(), h + 6); j++)
            if (!eqfunc()(ll[i], rr[j]))
                ans = lfmin(ans, dis(ll[i], rr[j]));
    }
    return lfmin(ans, d);
}
