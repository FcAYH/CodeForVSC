#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MaxV = 100000000000ll;

void Solve()
{
    ll cnt1, cnt2, x, y;
    scanf("%lld%lld%lld%lld", &cnt1, &cnt2, &x, &y);

    ll left = 0, right = MaxV;
    ll ans = 0;
    while (left <= right)
    {
        ll mid = (left + right) >> 1;
        ll val = mid - mid / (x * y);
        ll valX = mid - mid / x;
        ll valY = mid - mid / y;
        if (val >= cnt1 + cnt2 && valX >= cnt1 && valY >= cnt2)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    printf("%lld", ans);
}

int main()
{
    Solve();

    return 0;
}
