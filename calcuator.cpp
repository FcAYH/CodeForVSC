#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

char str[MAXN];

void Solve()
{
    freopen("data3.in", "r", stdin);
    freopen("data3.out", "w", stdout);

    scanf("%s", str);

    int length = strlen(str), sum = str[0] - '0';
    for (int i = 2; i < length; i += 2)
    {
        if (str[i - 1] == '+')
            sum += str[i] - '0';
        else
            sum -= str[i] - '0';
    }
    printf("%d", sum);
}

int main()
{
    Solve();

    return 0;
}
