#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MaxN = 1001010;

ll sl[MaxN];
struct Sequence
{
    ll v;
    int bh;
} q[MaxN];

void Solve()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &sl[i]);

    int head = 1, tail = 0;

    for (int i = 1; i <= n; i++)
    {
        while (head <= tail && q[tail].v >= sl[i])
            tail--;
        q[++tail].v = sl[i];
        q[tail].bh = i;
        if (i >= k)
        {
            while (head <= tail && q[head].bh < i - k + 1)
                head++;

            printf("%lld %d\n", q[head].v, q[head].bh);
        }
    }
}

int main()
{
    Solve();

    return 0;
}

/*
8 8
1 1 1 1 1 11 1 1
*/
