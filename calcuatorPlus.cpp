#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
const int INF = 100000;

char str[MAXN];

void Solve()
{
    freopen("data1.in", "r", stdin);
    // freopen("data12.out", "w", stdout);

    scanf("%s", str);

    int length = strlen(str), sum = 0;
    int kind = 1;
    for (int i = 1; i < length; i += 2)
    {
        if (str[i] == '*')
            kind = 2;
    }

    if (kind == 1)
    {
        sum = str[0] - '0';
        for (int i = 2; i < length; i += 2)
        {
            if (str[i - 1] == '+')
                sum += str[i] - '0';
            else
                sum -= str[i] - '0';
        }
    }
    else if (kind == 2)
    {
        sum = 0;
        int mul = str[0] - '0';
        for (int i = 2; i < length; i += 2)
        {
            if (str[i - 1] == '*')
            {
                mul *= str[i] - '0';
                mul %= INF;
            }
            else
            {
                sum += mul;
                mul = str[i] - '0';
                sum %= INF;
            }
        }
        sum += mul;
    }

    printf("%d", sum % INF);
}

int main()
{
    Solve();

    return 0;
}
