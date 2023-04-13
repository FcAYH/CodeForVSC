#include <bits/stdc++.h>

using namespace std;
float a[1010], b[1010];
float ans[2020];
void Solve()
{
    int ka, kb;
    cin >> ka;
    for (int i = 0; i < ka; i++)
    {
        int n;
        cin >> n;
        cin >> a[n];
    }
    cin >> kb;
    for (int i = 0; i < kb; i++)
    {
        int n;
        cin >> n;
        cin >> b[n];
    }
    int cnt = 0;
    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            ans[i + j] += a[i] * b[j];
        }
    }
    for (int i = 2000; i >= 0; i--)
        if (ans[i] != 0)
            cnt++;
    cout << cnt;
    for (int i = 2000; i >= 0; i--)
    {
        if (ans[i] != 0)
            printf(" %d %.1f", i, ans[i]);
    }
}

int main()
{
    Solve();

    return 0;
}
