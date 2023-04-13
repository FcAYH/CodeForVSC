#include <bits/stdc++.h>

using namespace std;

void Solve()
{
    int a[12];
    for (int i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < 10; i++)
    {
        if (a[i] > 0)
        {
            printf("%d", i);
            a[i]--;
            break;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        while (a[i])
        {
            printf("%d", i);
            a[i]--;
        }
    }
}

int main()
{
    Solve();

    return 0;
}
