#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _replace[3] = {2, 3, 6};

ll QuickPow(ll a, ll b)
{
    ll ret = 1;
    while (b)
    {
        if (b & 1)
            ret *= a;
        a = a * a;
        b >>= 1;
    }
    return ret;
}

void Solve()
{
    int n;
    scanf("%d", &n);
    n--;

    // if (n == 0)
    // {
    //     printf("2");
    //     return;
    // }

    ll counter = 0ll;
    int scale = 1;
    while (true)
    {
        ll tempCnt = counter + QuickPow(3, (ll)scale);

        if (tempCnt < (ll)n)
        {
            counter = tempCnt;
            scale++;
        }
        else
            break;
    }

    n -= counter;

    int *rec = new int[scale + 1];
    memset(rec, 0, sizeof(int) * (scale + 1));
    int nowPos = 0;
    while (n)
    {
        rec[nowPos++] = n % 3;
        n /= 3;
    }

    for (int i = scale - 1; i >= 0; i--)
        printf("%d", _replace[rec[i]]);
}

int main()
{
    Solve();

    return 0;
}
