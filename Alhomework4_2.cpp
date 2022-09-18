#include <bits/stdc++.h>

using namespace std;

const int Maxn = 101;

struct Point
{
    int x, y;

    static int cmp(const Point &p1, const Point &p2)
    {
        return (p1.x == p2.x) ? p1.y < p2.y : p1.x < p2.x;
    }

    void Print()
    {
        printf("(%d, %d)\n", x, y);
    }
};
class Graph
{
private:
    int vertexCount, edgeCount;
    Point *points;
    int timeCnt;
    int vis[Maxn];
    double area;

public:
    Graph() : timeCnt(0), area(0) {}
    Graph(int x, int y = 0) : vertexCount(x), edgeCount(y), timeCnt(0), area(0)
    {
        points = new Point[vertexCount + 1];
        for (int i = 0; i <= vertexCount; i++)
            vis[i] = 0;
    }
    ~Graph() { delete[] points; }

private:
    bool direction(Point a, Point b, Point c)
    {
        int x1 = b.x - a.x;
        int y1 = b.y - a.y;

        int x2 = c.x - a.x;
        int y2 = c.y - a.y;
        return (x1 * y2 - y1 * x2 > 0) ? true : false;
    }
    double getArea(Point a, Point b, Point c)
    {
        return fabs(0.5 * (a.x * b.y + b.x * c.y + c.x * a.y - a.x * c.y - b.x * a.y - c.x * b.y));
    }
    void caculate(bool flag, int left, int right)
    {
        double temp = -1.0;
        int k = 0;
        for (int i = left + 1; i <= right - 1; i++)
        {
            if (direction(points[left], points[right], points[i]) != flag)
            {
                continue;
            }
            if (temp < getArea(points[left], points[right], points[i]))
            {
                temp = getArea(points[left], points[right], points[i]);
                k = i;
            }
        }
        if (k == 0)
            return;

        vis[k] = 1;
        area += temp;
        caculate(flag, left, k);
        caculate(flag, k, right);
    }
    void Sort()
    {
        sort(points + 1, points + 1 + vertexCount, Point::cmp);
    }

public:
    void SetVertex(int x) { vertexCount = x; }
    void SetEdge(int x) { edgeCount = x; }
    void SetPoint(int x, int y)
    {
        points[++timeCnt].x = x,
        points[timeCnt].y = y;
    }
    double ConvexHull();
};

double Graph::ConvexHull()
{
    Sort();
    vis[1] = 1, vis[vertexCount] = 1;
    caculate(true, 1, vertexCount);
    caculate(false, 1, vertexCount);

    int cnt = 0;
    for (int i = 1; i <= vertexCount; i++)
        if (vis[i])
            cnt++;
    printf("%d\n", cnt);
    for (int i = 1; i <= vertexCount; i++)
        if (vis[i])
            points[i].Print();

    return area;
}

void Solve()
{
    int n;
    scanf("%d", &n);

    Graph G(n);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        G.SetPoint(x, y);
    }

    double ans = G.ConvexHull();
    printf("%.2lf\n", ans);
}

int main()
{
    Solve();

    return 0;
}
/*
5
0 0
0 1
1 0
1 1
2 1
*/
