#include <bits/stdc++.h>

using namespace std;

const int MaxN = 100010;

int seq[MaxN];
int prefix[MaxN];

void Solve()
{
    int n = 0;
    scanf("%d", &n);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &seq[i]);
        sum += seq[i];
        prefix[i] = seq[i];
        if (i != 0)
            prefix[i] += prefix[i - 1];
    }

    if (sum % 3 || n < 3)
    {
        printf("0");
        return;
    }

    int val = sum / 3;
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (prefix[i] == 2 * val)
            ans += cnt;
        if (prefix[i] == val)
            cnt++;
    }

    printf("%d", ans);
}

int main()
{
    Solve();

    return 0;
}
