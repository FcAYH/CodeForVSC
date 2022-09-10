#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x)
{
    if (x <= 1)
        return false;
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            return false;
    }

    return true;
}

void Solve()
{
    int n;
    scanf("%d", &n);

    if (isPrime(n) && (isPrime(n + 2) || isPrime(n - 2)))
        printf("y");
    else
        printf("n");
}

int main()
{
    Solve();

    return 0;
}
