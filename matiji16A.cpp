#include <bits/stdc++.h>

using namespace std;

const int MaxN = 1000010;

int in[MaxN];
int out[MaxN];

void Solve()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);

        in[y]++;
        out[x]++;
    }

    bool flag = true;
    int stc = 0, edc = 0;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == out[i])
            continue;

        if (in[i] == out[i] + 1)
            edc++;
        else if (in[i] + 1 == out[i])
            stc++;
        else
            flag = false;
    }

    if (flag == false)
    {
        printf("No");
        return;
    }

    if (((edc == 1 && stc == 1) || (edc == 0 && stc == 0)))
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
}

int main()
{
    Solve();

    return 0;
}
