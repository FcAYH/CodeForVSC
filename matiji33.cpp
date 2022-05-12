#include <bits/stdc++.h>

using namespace std;

const int MaxN = 100001;
int a[MaxN];

inline int cmp(int a, int b)
{
    return a < b;
}

void Solve()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);

        set<int> numSet;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            numSet.insert(a[i]);
        }

        sort(a, a + n, cmp);

        int maxNum = a[n - 1], minNum = 0;

        if (a[1] > 1)
            minNum = 1;
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (numSet.count(a[i] + 1) == 0)
                {
                    minNum = a[i] + 1;
                    break;
                }
            }
        }

        if (minNum > maxNum)
        {
            printf("%d\n", n + k);
        }
        else if (numSet.count(ceil(((double)minNum + maxNum) / 2)) == 1)
        {
            printf("%d\n", n);
        }
        else
        {
            printf("%d\n", n + 1);
        }
    }
}

int main()
{
    Solve();

    return 0;
}
