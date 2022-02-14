#include <bits/stdc++.h>

using namespace std;

const int MAX_HEIGHT = 5;
const int MAX_WIDTH = 500;

char ans[MAX_HEIGHT][MAX_WIDTH];

char table[10][5][5] = {
    "XXX.",
    "X.X.",
    "X.X.",
    "X.X.",
    "XXX.",

    "..X.",
    "..X.",
    "..X.",
    "..X.",
    "..X.",

    "XXX.",
    "..X.",
    "XXX.",
    "X...",
    "XXX.",

    "XXX.",
    "..X.",
    "XXX.",
    "..X.",
    "XXX.",

    "X.X.",
    "X.X.",
    "XXX.",
    "..X.",
    "..X.",

    "XXX.",
    "X...",
    "XXX.",
    "..X.",
    "XXX.",

    "XXX.",
    "X...",
    "XXX.",
    "X.X.",
    "XXX.",

    "XXX.",
    "..X.",
    "..X.",
    "..X.",
    "..X.",

    "XXX.",
    "X.X.",
    "XXX.",
    "X.X.",
    "XXX.",

    "XXX.",
    "X.X.",
    "XXX.",
    "..X.",
    "XXX."};

void Solve()
{
    int n;
    scanf("%d", &n);

    char *str = new char[n + 1];
    scanf("%s", str);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                ans[j][4 * i + k] = table[str[i] - '0'][j][k];
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < n * 4 - 1; j++)
        {
            printf("%c", ans[i][j]);
        }
        puts("");
    }
}

int main()
{
    Solve();

    return 0;
}

/*
XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX
X.X...X...X...X.X.X.X...X.....X.X.X.X.X
X.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXX
X.X...X.X.....X...X...X.X.X...X.X.X...X
XXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX
*/
