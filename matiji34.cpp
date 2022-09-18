#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

void gcd(int a, int b)
{
    cnt++;
    if (a == 0 || b == 0)
        return;

    a > b ? gcd(a - b, b) : gcd(b - a, a);
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    gcd(a, b);

    printf("%d", cnt - 1);

    return 0;
}
