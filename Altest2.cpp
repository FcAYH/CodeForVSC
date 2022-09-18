#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0);

class Round
{
public:
    Round() {}
    Round(double x, double y, double r)
    {
        this->x = x, this->y = y, this->r = r;
    }
    void getval();
    const double OverlapArea(Round);

private:
    double x, y, r;
};

void Round::getval()
{
    scanf("%lf%lf%lf", &this->x, &this->y, &this->r);
}
const double Round::OverlapArea(Round R2)
{
    double x1 = this->x, x2 = R2.x, y1 = this->y, y2 = R2.y, r1 = this->r, r2 = R2.r;

    double dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    if (dist - r1 - r2 >= 0)
        return 0.0;
    if (dist + r2 <= r1 || dist + r1 <= r2)
        return min(r1 * r1 * pi, r2 * r2 * pi);

    double Cos2R1 = (r1 * r1 + dist * dist - r2 * r2) / (2.0 * r1 * dist);
    double Angle1 = acos(Cos2R1) * 2.0;
    double S1 = Angle1 * r1 * r1 / 2.0;
    double Sr1 = sin(Angle1) * r1 * r1 / 2.0;

    double Cos2R2 = (r2 * r2 + dist * dist - r1 * r1) / (2.0 * r2 * dist);
    double Angle2 = acos(Cos2R2) * 2.0;
    double S2 = Angle2 * r2 * r2 / 2.0;
    double Sr2 = sin(Angle2) * r2 * r2 / 2.0;

    return S1 - Sr1 + S2 - Sr2;
}

void Solve()
{
    Round R1, R2;
    R1.getval(), R2.getval();

    double S = R1.OverlapArea(R2);
    printf("%.3lf", S);
}

int main()
{
    Solve();

    return 0;
}
/*
30 40 30 
15 15 15 
*/
