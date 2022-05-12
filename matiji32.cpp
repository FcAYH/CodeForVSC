#include <bits/stdc++.h>

using namespace std;

const int Maxn = 100000001;

int n, len = 0;
bool Not_p[Maxn];
int prime[Maxn];

inline void Ini()
{
    Not_p[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (!Not_p[i])
            prime[++len] = i;
        for (int j = 1; j <= len; j++)
        {
            if (i * prime[j] > n)
                break;
            Not_p[i * prime[j]] = 1;
            if (!(i % prime[j]))
                break;
        }
    }
}
int main()
{
    scanf("%d", &n);

    Ini();

    printf("%.3lf\n", (double)len / n);

    return 0;
}
