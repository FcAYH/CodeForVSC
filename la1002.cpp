#include <bits/stdc++.h>

using namespace std;
float a[1010];
float b[1010];

void Solve()
{
    int k1;
    cin >> k1;
    for (int i = 0; i < k1; i++)
    {
        int n;
        scanf("%d", &n);
        scanf("%f", &a[n]);
    }
    int k2;
    cin >> k2;

    for (int i = 0; i < k2; i++)
    {
        int n;
        scanf("%d", &n);
        scanf("%f", &b[n]);
    }
    int count = 0;
    for (int i = 0; i < 1001; i++)
    {
        b[i] += a[i];
        if (b[i] != 0)
            count++;
    }
    cout << count;
    for (int i = 1001; i >= 0; i--)
    {
        if (b[i] != 0)
            printf(" %d %.1f", i, b[i]);
    }
}

int main()
{
    Solve();

    return 0;
}

/*
    2   1   0
    0   2.4  3.2
    1.5 0.5  0
    1.5 2.9 3.2

a: 0     1     2 -> 多项式

b: 0     1     2

5 1000 0.5  400 3.4 20 1.3 4 0.8 0 9


*/
