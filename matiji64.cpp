#include <bits/stdc++.h>

using namespace std;

void Solve()
{
    int m;
    scanf("%d", &m);

    while (m--)
    {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

        int dx1, dy1, dx2, dy2;
        dx1 = (x2 - x1);
        dy1 = (y2 - y1);
        dx2 = (x4 - x3);
        dy2 = (y4 - y3);

        if (dx1 * dx2 + dy1 * dy2 == 0)
            printf("1\n");
        else if (dx1 * dy2 == dy1 * dx2)
            printf("2\n");
        else
            printf("0\n");
    }
}

int main()
{
    Solve();

    return 0;
}
