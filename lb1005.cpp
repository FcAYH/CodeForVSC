#include <bits/stdc++.h>

using namespace std;

int num[110];
int vis[101];

void Solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        // num[i] => *(num + i);
    }
    sort(num, num + n);
    for (int i = 0; i < n; i++)
    {
        int temp = num[i];
        if (vis[temp] == 0)
        {
            while (temp != 1)
            {
                //     cout << num[i] << " ";
                if (temp % 2 == 0)
                {
                    temp = temp / 2;
                }
                else
                {
                    temp = (3 * temp + 1) / 2;
                }
                if (temp <= 100)
                    vis[temp]++;
            }
            //   cout << "\n";
        }
    }
    int flag = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (vis[num[i]] == 0)
        {
            if (flag == 1)
                printf("%d", num[i]);
            else
                printf(" %d", num[i]);
            flag++;
        }
    }
}

int main()
{
    Solve();

    return 0;
}
