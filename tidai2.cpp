#include <bits/stdc++.h>

using namespace std;

void Solve()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int x, y, a, b, c;
        scanf("%d%d%d%d%d", &x, &y, &a, &b, &c);

        int temp1 = y % c;
        int temp2 = x % b;

        printf("%d\n", max((x + (y / a)) / b, (x / b) + (y / c) + (temp2 + temp1 / a) / b));
    }
}

int main()
{
    Solve();

    return 0;
}
