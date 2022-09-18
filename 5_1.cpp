#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5;

int vis[Maxn][Maxn];
int Map[Maxn][Maxn];
int R, C;

int dfs(int i, int j)
{
    printf("%d %d\n", i, j);
    int Max = 0;
    if (i - 1 >= 0)
        if (Map[i - 1][j] < Map[i][j])
            Max = max(Max, dfs(i - 1, j));
    if (i + 1 < R)
        if (Map[i + 1][j] < Map[i][j])
            Max = max(Max, dfs(i + 1, j));
    if (j - 1 >= 0)
        if (Map[i][j - 1] < Map[i][j])
            Max = max(Max, dfs(i, j - 1));
    if (j + 1 < C)
        if (Map[i][j + 1] < Map[i][j])
            Max = max(Max, dfs(i, j + 1));
    return Max + 1;
}

int dp(int i, int j)
{
    int Max = 0;
    if (vis[i][j] > 0)
        return vis[i][j];
    if (i - 1 >= 0)
        if (Map[i - 1][j] < Map[i][j])
            Max = max(Max, dp(i - 1, j));
    if (i + 1 < R)
        if (Map[i + 1][j] < Map[i][j])
            Max = max(Max, dp(i + 1, j));
    if (j - 1 >= 0)
        if (Map[i][j - 1] < Map[i][j])
            Max = max(Max, dp(i, j - 1));
    if (j + 1 < C)
        if (Map[i][j + 1] < Map[i][j])
            Max = max(Max, dp(i, j + 1));
    return vis[i][j] = Max + 1;
}

void Solve()
{
    //freopen("output.csv", "w", stdout);

    srand(time(0));

    // for (R = 10; R <= 200; R += 5)
    // {
    // printf("%d,", R);

    // C = R;

    int i, j, ans, Max;
    scanf("%d%d", &R, &C);
    for (i = 0; i < R; i++)
        for (j = 0; j < C; j++)
            // Map[i][j] = rand() % 100; //
            scanf("%d", &Map[i][j]);

    Max = 0;
    memset(vis, -1, sizeof(vis));

    // clock_t start, end;

    // start = clock();

    // for (i = 0; i < R; i++)
    // {
    //     for (j = 0; j < C; j++)
    //     {
    //         if (vis[i][j] == -1)
    //         {
    //             ans = dp(i, j);
    //             Max = max(Max, ans);
    //         }
    //     }
    // }

    // end = clock();
    // printf("%d,", end - start);

    // start = clock();

    int ANS = 0, MAX = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            ANS = dfs(i, j);
            MAX = max(MAX, ANS);
            puts("");
        }
    }

    // end = clock();
    // printf("%d\n", end - start);

    printf("%d --- %d\n", Max, MAX);
    //}
}
int main()
{
    Solve();

    return 0;
}

/*
5 5
 1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

4 4
 6  5 31  2
 7  8 12 15
60 17 18  9
16 71  1  5
*/
