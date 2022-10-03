#include <bits/stdc++.h>

using namespace std;

const int MaxN = 1000100;

int num = 0;
int prime[MaxN];
bool not_prime[MaxN];

void Init()
{
    not_prime[1] = 1;
    for (int i = 2; i < MaxN - 10; i++)
    {
        if (!not_prime[i])
        {
            prime[num++] = i;
        }
        for (int j = 0; j < num; j++)
        {
            if (i * prime[j] >= MaxN)
                break;
            not_prime[i * prime[j]] = true;
            if (!(i % prime[j]))
                break;
        }
    }
}

bool check(int x)
{
    int cnt = 0;
    int number[10];
    while (x)
    {
        number[cnt++] = x % 10;
        x /= 10;
    }

    for (int i = 0; i < cnt; i++)
    {
        if (number[i] != number[cnt - i - 1])
            return false;
    }

    return true;
}

void Solve()
{
    Init();

    int n, m;
    scanf("%d%d", &n, &m);

    bool flag = false;
    for (int i = n; i <= m; i++)
    {
        if (!(not_prime[i]) && check(i))
        {
            flag = true;
            printf("%d\n", i);
        }
    }
    if (!flag)
    {
        printf("NO");
    }
}

int main()
{
    Solve();

    return 0;
}
