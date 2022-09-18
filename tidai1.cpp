#include <bits/stdc++.h>

using namespace std;

void Solve()
{
    int n;
    scanf("%d", &n);

    int a, b, cnt = 0;
    while (scanf("%d%d", &a, &b) != EOF)
        cnt++;

    printf("%d", cnt);
}

int main()
{
    Solve();

    return 0;
}
