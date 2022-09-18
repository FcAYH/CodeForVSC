#include <bits/stdc++.h>

using namespace std;

const int Maxn = 500;

int n;
int trans[Maxn];
int playt[4][Maxn];

int check(int keller, int why, int dyp)
{
    int toTK[Maxn], goTK[Maxn];
    int toTW[Maxn], goTW[Maxn];
    int toTD[Maxn], goTD[Maxn];

    toTK[keller] = 0, toTW[why] = 0, toTD[dyp] = 0;
    for (int i = keller; i <= n; i++)
    {
        goTK[i] = toTK[i] + playt[1][i];
        if (i != n)
            toTK[i + 1] = goTK[i] + trans[i];
        if (i == n && keller != 1)
            toTK[1] = goTK[i] + trans[i];
    }
    for (int i = 1; i < keller; i++)
    {
        goTK[i] = toTK[i] + playt[1][i];
        if (i != keller - 1)
            toTK[i + 1] = goTK[i] + trans[i];
    }

    for (int i = why; i <= n; i++)
    {
        goTW[i] = toTW[i] + playt[2][i];
        if (i != n)
            toTW[i + 1] = goTW[i] + trans[i];
        if (i == n && why != 1)
            toTW[1] = goTW[i] + trans[i];

        if (toTW[i] > toTK[i] && toTW[i] < goTK[i] || toTK[i] > toTW[i] && toTK[i] < goTW[i])
            return 0;
    }
    for (int i = 1; i < why; i++)
    {
        goTW[i] = toTW[i] + playt[2][i];
        if (i != why - 1)
            toTW[i + 1] = goTW[i] + trans[i];

        if (toTW[i] > toTK[i] && toTW[i] < goTK[i] || toTK[i] > toTW[i] && toTK[i] < goTW[i])
            return 0;
    }

    for (int i = dyp; i <= n; i++)
    {
        goTD[i] = toTD[i] + playt[3][i];
        if (i != n)
            toTD[i + 1] = goTD[i] + trans[i];
        if (i == n && dyp != 1)
            toTD[1] = goTD[i] + trans[i];

        if (toTD[i] > toTK[i] && toTD[i] < goTK[i] || toTK[i] > toTD[i] && toTK[i] < goTD[i])
            return 0;
        if (toTW[i] > toTD[i] && toTW[i] < goTD[i] || toTD[i] > toTW[i] && toTD[i] < goTW[i])
            return 0;
    }
    for (int i = 1; i < dyp; i++)
    {
        goTD[i] = toTD[i] + playt[3][i];
        if (i != dyp - 1)
            toTD[i + 1] = goTD[i] + trans[i];

        if (toTD[i] > toTK[i] && toTD[i] < goTK[i] || toTK[i] > toTD[i] && toTK[i] < goTD[i])
            return 0;
        if (toTW[i] > toTD[i] && toTW[i] < goTD[i] || toTD[i] > toTW[i] && toTD[i] < goTW[i])
            return 0;
    }

    // if (keller == 1 && why == 5 && dyp == 6)
    // {
    //     for (int i = 1; i <= n; i++)
    //     {
    //         printf("(%d, %d) ", toTK[i], goTK[i]);
    //     }
    //     puts("");
    //     for (int i = 1; i <= n; i++)
    //     {
    //         printf("(%d, %d) ", toTW[i], goTW[i]);
    //     }
    //     puts("");
    //     for (int i = 1; i <= n; i++)
    //     {
    //         printf("(%d, %d) ", toTD[i], goTD[i]);
    //     }
    //     puts("");
    // }
    return 1;
}

void Solve()
{
    scanf("%d ", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &trans[i]);

    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &playt[i][j]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (i != j && j != k && i != k && check(i, j, k))
                {
                    printf("%d %d %d", i, j, k);
                    return;
                }

    printf("impossible");
}

int main()
{
    Solve();

    return 0;
}
