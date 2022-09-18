#include <iostream>

using namespace std;

struct Point
{
    double x, y;

    Point(int x, int y) : x(x), y(y) {}
};

int LineIntersectSide(Point A, Point B, Point C, Point D)
{
    double fC = (C.y - A.y) * (A.x - B.x) - (C.x - A.x) * (A.y - B.y);
    double fD = (D.y - A.y) * (A.x - B.x) - (D.x - A.x) * (A.y - B.y);

    return (fC * fD > 0) ? false : true;
}

int SideIntersectSide(Point A, Point B, Point C, Point D)
{
    if (!LineIntersectSide(A, B, C, D))
        return false;
    if (!LineIntersectSide(C, D, A, B))
        return false;

    return true;
}

void Solve()
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

    Point P1(x1, y1);
    Point P2(x2, y2);
    Point P3(x3, y3);
    Point P4(x4, y4);

    printf("%s", (SideIntersectSide(P1, P2, P3, P4)) ? "Yes" : "No");
}

int main()
{
    Solve();

    return 0;
}
