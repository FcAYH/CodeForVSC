#include <bits/stdc++.h>

using namespace std;
int a[110][110];
void Solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    if (k >= 1)
    {
        int flag = 1;
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 != 0)
            {
                for (int j = n; j > 0; j--)
                {
                    if (j + flag <= n)
                    {
                        a[i][j + flag] = a[i][j];
                    }
                    a[i][j] = x;
                }
                flag++;
                if (flag > k)
                    flag = 1;
            }
        }
    }

    // for (int j = 1; j <= n; j++)
    // {
    //     for (int i = 1; i <= n; i++)
    //         cout << a[j][i] << " ";
    //     cout << "\n";
    // }

    for (int j = 1; j <= n; j++)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += a[i][j];
        }
        if (j == 1)
        {
            printf("%d", sum);
        }
        else
            printf(" %d", sum);
    }
}

int main()
{
    Solve();

    return 0;
}
