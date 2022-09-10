#include <bits/stdc++.h>

using namespace std;

const int MaxN = 10001;

int notPrime[MaxN];

bool IsPrime(int x)
{
    if (x == 1)
        return false;

    for (int i = 2; i <= sqrt(x); i++)
    {
        if (!(x % i))
            return false;
    }

    return true;
}

void Init()
{
    notPrime[1] = true;
    for (int i = 2; i <= 100; i++)
    {
        if (!notPrime[i])
        {
            int x = 2 * i;
            while (x <= 100)
            {
                notPrime[x] = true;
                x += i;
            }
        }
    }
}

int main()
{
    Init();
    for (int i = 1; i <= 100; i++)
    {
        if (IsPrime(i))
        {
            printf("%d ", i);
        }
    }
}
