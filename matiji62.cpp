#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isPrime(ll x)
{
    for (ll i = 2; i <= sqrt(x); i++)
        if (!(x % i))
            return false;

    return true;
}

int main()
{
    ll n;
    scanf("%lld", &n);
    printf("%s", isPrime(n) ? "YES" : "NO");
    return 0;
}
