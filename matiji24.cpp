#include <bits/stdc++.h>

using namespace std;

void Solve()
{
    int x1, y1, r1;
    int x2, y2, r2;

    scanf("%d%d%d", &x1, &y1, &r1);
    scanf("%d%d%d", &x2, &y2, &r2);

    if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) >= (r1 + r2) * (r1 + r2))
        printf("NO");
    else
    {
        if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= (r1 - r2) * (r1 - r2))
            printf("NO");
        else
            printf("YES");
    }
}

int main()
{
    Solve();

    return 0;
}
