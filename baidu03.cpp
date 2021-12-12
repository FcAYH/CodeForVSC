#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

void Solve()
{
    ll n;
    scanf("%lld", &n);
    if (n < 0)
        printf("0");
    else
    {
        ll ans = 1;
        for (int i = 2; i <= n; i++)
        {
            ans *= i;
        }

        printf("%d", ans);
    }
}

int main()
{
    Solve();

    return 0;
}
