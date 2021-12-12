#include <bits/stdc++.h>

using namespace std;

void Solve()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    printf("%d", 2 * c * (a + 2 * c) + b * c * 2);
}

int main()
{
    Solve();

    return 0;
}
