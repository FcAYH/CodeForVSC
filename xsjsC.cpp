#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void Solve()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ll n;
        scanf("%lld", &n);

        ll sum = 0;
        for (ll i = 1; i <= sqrt(n); i++)
        {
            if (!(n % i))
            {
                sum += i;
                if ((n / i) * (n / i) != n)
                    sum += n / i;
            }
        }

        printf("%lld\n", sum);
    }
}

int main()
{
    Solve();

    return 0;
}
