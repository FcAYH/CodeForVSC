#include <iostream>
#include <cmath>

using namespace std;

inline double Distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void Solve()
{
    double x1, y1, x2, y2;
    scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);

    printf("%.3lf", Distance(x1, y1, x2, y2));
}

int main()
{
    Solve();

    return 0;
}
