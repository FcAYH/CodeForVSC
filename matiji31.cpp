#include <bits/stdc++.h>

using namespace std;

long long D[22];

int main()
{
    int n;
    scanf("%d", &n);

    // D(n) = (n-1) [D(n-2) + D(n-1)]
    D[1] = 0;
    D[2] = 1;
    for (long long i = 3; i <= n; i++)
    {
        D[i] = (i - 1) * (D[i - 2] + D[i - 1]);
    }

    printf("%lld", D[n]);

    return 0;
}
