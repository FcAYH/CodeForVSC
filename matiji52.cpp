#include <bits/stdc++.h>

using namespace std;

bool IsInElliptical(float x, float y, float a, float b)
{
    return (x * x) / (a * a) + (y * y) / (b * b) < 1.0;
}

void Solve()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);

    while (n--)
    {
        double x, y;
        scanf("%lf%lf", &x, &y);

        printf("%s\n", (IsInElliptical(x, y, (float)a, (float)b)) ? "True" : "False");
    }
}

int main()
{
    Solve();

    return 0;
}
