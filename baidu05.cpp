#include <bits/stdc++.h>

using namespace std;

const int timeRequired[10] = {1, 2, 5, 10, 12, 23, 43, 50, 120, 122};

int Calc(int n)
{
    int sum = 0;
    if (n == 1)
    {
        sum = timeRequired[0];
        return sum;
    }
    if (n == 2)
    {
        sum = timeRequired[1];
        return sum;
    }
    if (n == 3)
    {
        sum = timeRequired[0] + timeRequired[1] + timeRequired[2];
        return sum;
    }
    if (2 * timeRequired[1] >= timeRequired[0] + timeRequired[n])
    {
        sum = sum + timeRequired[n - 1] + timeRequired[0] * 2 +
              timeRequired[n - 2] + Calc(n - 2);
    }
    else
    {
        sum = sum + timeRequired[1] + timeRequired[0] + timeRequired[n - 1] +
              timeRequired[1] + Calc(n - 2);
    }
    return sum;
}

void Solve()
{
    int n;
    scanf("%d", &n);

    int ans = Calc(n);
    printf("%d\n", ans);
}

int main()
{
    Solve();

    return 0;
}

/*
1 1
2 1 2
3 1 2 -> 1, 1 5 = 8
4
*/
