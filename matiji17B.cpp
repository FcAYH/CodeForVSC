#include <bits/stdc++.h>

using namespace std;

const int MaxN = 100010;

int a[MaxN];

int cmp(int x, int y)
{
    return x > y;
}

void Solve()
{
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    sort(a, a + n, cmp);

    int cnt = 1, last = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > 0 && (cnt < k || a[i] == last))
        {
            cnt++;
            last = a[i];
        }
        else
            break;
    }

    printf("%d", cnt);
}

int main()
{
    Solve();

    return 0;
}
