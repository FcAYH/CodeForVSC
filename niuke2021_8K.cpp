#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const double pi = acos(-1);

int solve1(double w, double d)
{
    int ans = 4;
    double a = min(w, d);
    ans += (int)(pi / a) * 2;
    return ans;
}
int solve2(double w, double d)
{
    int ans = 4;
    double rest = pi;
    double a = sqrt(pow(w, 2) + pow(d, 2));
    double b = min(w, d);
    ans += (int)(pi / a) * 3;
    rest -= (int)(pi / a) * a;
    if (rest > b)
        ans += 2 * (int)(rest / b);
    return ans;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int ans1, ans2;
        double w, d, rest = pi;
        cin >> w >> d;
        ans1 = solve1(w, d);
        ans2 = solve2(w, d);
        cout << max(ans1, ans2) << endl;
    }
    return 0;
}
