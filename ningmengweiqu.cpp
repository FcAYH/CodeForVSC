#include <bits/stdc++.h>

using namespace std;

const int MaxN = 10010;

void Solve()
{
    int n;
    scanf("%d", &n);

    int *num = new int[n - 1];

    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &num[i]);
    }

    int left = 1, right = n;
    int ans = 0;
    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if (mid == n - 1)
        {
            ans = n;
            break;
        }
        if (num[mid - 1] > mid)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    printf("%d", ans);
}

int main()
{
    Solve();

    return 0;
}

/*
10
1 2 4 5 6 7 8 9 10

10
1 2 3 4 5 6 7 8 9

10
2 3 4 5 6 7 8 9 10
*/
