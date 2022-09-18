#include <cstdio>
#include <cmath>
#include <cstdlib>
#define PI 3.1415926535897932384626433

double insection(double x1, double y1, double x2, double y2, double r1, double r2)
{
    double distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    //相离
    if (r1 + r2 < distance)
        return 0.0;
    //内含
    else if (abs(r2 - r1) >= distance)
    {
        if (r2 >= r1)
            return PI * r1 * r1;
        else
            return PI * r2 * r2;
    }
    //相交
    else
    {
        double angle1 = 2 * acos((r1 * r1 + distance * distance - r2 * r2) / 2 / r1 / distance);
        double angle2 = 2 * acos((r2 * r2 + distance * distance - r1 * r1) / 2 / r2 / distance);
        double ans = r1 * r1 * angle1 / 2 + r2 * r2 * angle2 / 2 - r1 * r1 * sin(angle1) / 2 - r2 * r2 * sin(angle2) / 2;
        return ans;
    }
    return 0;
}
int main()
{
    double x1, y1, r1, x2, y2, r2;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);

    double ans = insection(x1, y1, x2, y2, r1, r2);
    printf("%.3lf\n", ans);

    return 0;
}
