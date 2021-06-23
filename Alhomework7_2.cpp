#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int Maxn = 1010;

int n;
int Map[Maxn][Maxn];
int color[Maxn];
int color_num = 0;
char temp[Maxn];

bool CheckColor(int i, int num)
{
    for (int j = 0; j < n; j++)
    {
        if (Map[i][j] == 1)
            if (color[j] == num)
                return false;
    }
    return true;
}
void dfs(int cur)
{
    if (cur >= n)
    {
        printf("%d\n", color_num);
        return;
    }
    else
    {
        int i;
        for (i = 1; i <= cur; i++)
        {
            color[cur] = i;

            if (CheckColor(cur, i))
            {
                dfs(cur + 1);
                return;
            }
        }

        color[cur] = i;
        if (CheckColor(cur, i))
        {
            color_num++;

            dfs(cur + 1);
        }
    }
}

void Solve()
{
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", temp);

        for (int j = 2; temp[j] != 0; j++)
            Map[i][temp[j] - 'A'] = 1;
    }

    dfs(0);
}

int main()
{
    Solve();

    return 0;
}

/*
4
A:BCD
B:ACD
C:ABD
D:ABC

*/
