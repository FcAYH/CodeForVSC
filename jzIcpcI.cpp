#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;

struct Ant
{
    int pos, v;
} ants[MAXN];

inline int cmp(Ant a, Ant b)
{
    return a.pos < b.pos;
}

void Solve()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &ants[i].pos);
    }

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &ants[i].v);
    }

    sort(ants + 1, ants + 1 + n, cmp);

    for (int i = 1; i <= n; i++)
    {
        }
}

int main()
{
    Solve();

    return 0;
}
