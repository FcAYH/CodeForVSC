#include <bits/stdc++.h>

using namespace std;

const int MaxN = 5000001;

typedef unsigned int uint;

uint num[MaxN];

void Solve()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    unsigned int ans = num[0];
    for (int i = 1; i < n; i++)
    {
        ans = (!ans) | num[i];
    }

    cout << ans;
}

int main()
{
    Solve();

    return 0;
}
