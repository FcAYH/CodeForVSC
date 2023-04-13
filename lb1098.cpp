#include <bits/stdc++.h>

using namespace std;
int high[110];
int low[110];
void Solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> high[i];
    for (int i = 0; i < n; i++)
        cin >> low[i];
    int minn = INT32_MAX, maxx = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        if (high[i] < minn)
            minn = high[i];
        if (low[i] > maxx)
            maxx = low[i];
    }
    if ((minn - maxx) >= 1)
        printf("Yes %d", minn - maxx);
    else
        printf("No %d", abs(maxx - minn) + 1);
}

int main()
{
    Solve();

    return 0;
}
