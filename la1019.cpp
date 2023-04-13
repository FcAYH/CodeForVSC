#include <bits/stdc++.h>

using namespace std;
int a[35];
int isPali(int i)
{
    for (int left = 0, right = i - 1; left < right; left++, right--)
    {
        if (a[left] != a[right])
            return 0;
    }
    return 1;
}

void Solve()
{
    int n, b;
    cin >> n >> b;
    if (n == 0)
    {
        printf("Yes\n,0");
        return;
    }
    int i = 0;
    while (n != 0)
    {
        a[i] = n % b;
        n = n / b;
        i++;
    }

    switch (isPali(i))
    {
    case 1:
        printf("Yes\n%d", a[i - 1]);
        break;
    case 0:
        printf("No\n%d", a[i - 1]);
        break;
    }

    for (int j = i - 2; j >= 0; j--)
        printf(" %d", a[j]);
}

int main()
{
    Solve();

    return 0;
}
