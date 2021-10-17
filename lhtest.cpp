#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1010;

int tol[Maxn];
int tArray[Maxn];

inline int cmp(int x, int y)
{
    return x < y;
}

void Solve()
{
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &tol[i]);
        tArray[i] = tol[i];
    }

    sort(tArray + 1, tArray + 1 + m, cmp);

    int ans = 0;
    int solved = 0, nowp = 1;
    while (true)
    {
        while (tol[nowp] != tArray[solved + 1])
        {
            nowp++;
            if (nowp == m + 1)
                nowp = 1;
        }
        if (tol[nowp] == tArray[solved + 1])
        {
            solved++;
            if (nowp == n)
            {
                ans = solved;
                break;
            }
        }
    }

    printf("%d", ans);
}

int main()
{
    Solve();

    return 0;
}
