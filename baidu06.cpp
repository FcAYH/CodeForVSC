#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MaxAns = 0;
vector<ll> record;

void dfs(ll remain, int count)
{
    if (remain == 0)
    {
        ll tempModify = 1;
        for (int i = 1; i < count; i++)
        {
            tempModify *= record[i];
            // printf("%d ", record[i]);
        }
        if (tempModify > MaxAns)
            MaxAns = tempModify;
        // puts("");
    }
    else
    {
        for (ll i = min(remain, record[count - 1]); i <= remain; i++)
        {
            record.push_back(i);
            dfs(remain - i, count + 1);
            record.pop_back();
        }
    }
}

void Solve()
{
    int n;
    scanf("%d", &n);
    if (n == 0)
        printf("%d", 0);
    else
    {
        record.push_back(2);
        dfs(n, 1);

        printf("%lld", MaxAns);
    }
}

int main()
{
    Solve();

    return 0;
}
