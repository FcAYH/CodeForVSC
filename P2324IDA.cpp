#include <bits/stdc++.h>

using namespace std;

const int MaxN = 7;
const int MaxOper = 16;
const int Inf = 0x3f3f3f3f;

char ansBoard[][MaxN] = {
    "000000",
    "011111",
    "001111",
    "000*11",
    "000001",
    "000000"};

int Ans = Inf;
char board[MaxN][MaxN];
int dx[] = {0, -2, -2, -1, 1, 2, 2, 1, -1};
int dy[] = {0, -1, 1, 2, 2, 1, -1, -2, -2};

int Evaluate()
{
    int counter = 0;
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            if (board[i][j] != ansBoard[i][j])
                counter++;

    return counter;
}

inline int CheckReturnOper(int i, int j)
{
    return (dx[i] == -dx[j]) && (dy[i] == -dy[j]);
}

int AStar(int x, int y, int operCnt, int lastStatus, int maxDepth)
{
    int eval = Evaluate();
    if (eval == 0)
    {
        //printf("GetAns!!!\n");
        Ans = min(Ans, operCnt);
        return 1;
    }

    if (eval + operCnt > min(Ans, MaxOper))
        return 0;
    if (maxDepth == 0)
        return 0;

    for (int i = 1; i <= 8; i++)
    {
        if (CheckReturnOper(i, lastStatus))
            continue;

        int nextX = x + dx[i], nextY = y + dy[i];

        if (nextX >= 1 && nextX <= 5 && nextY >= 1 && nextY <= 5)
        {
            //printf("%d %d %d %d\n", x, y, nextX, nextY);
            swap(board[x][y], board[nextX][nextY]);
            int getFlag = AStar(nextX, nextY, operCnt + 1, i, maxDepth - 1);
            swap(board[x][y], board[nextX][nextY]);

            if (getFlag == 1)
                return 1;
        }
    }
    return 0;
}

void Solve()
{
    int t = 0;
    scanf("%d", &t);

    while (t--)
    {
        for (int i = 1; i <= 5; i++)
            scanf("%s", board[i] + 1);

        int diff = Evaluate();

        if (!diff)
        {
            printf("0\n");
            continue;
        }

        int startX = 0, startY = 0;
        for (int i = 1; i <= 5; i++)
            for (int j = 1; j <= 5; j++)
                if (board[i][j] == '*')
                    startX = i, startY = j;

        Ans = Inf;
        for (int i = diff; i <= MaxOper; i++)
        {
            int getFlag = AStar(startX, startY, 0, 0, i);
            if (getFlag == 1)
                break;
        }
        printf("%d\n", (Ans == Inf) ? -1 : Ans);
    }
}

int main()
{
    Solve();

    return 0;
}
/*

x: -2 -2 -1 +1 +2 +2 +1 -1
y: -1 +1 +2 +2 +1 -1 -2 -2
(1, 1) (1, 2) (1, 3) (1, 4) (1, 5)
(2, 1) (2, 2) (2, 3) (2, 4) (2, 5)
(3, 1) (3, 2) (3, 3) (3, 4) (3, 5)
(4, 1) (4, 2) (4, 3) (4, 4) (4, 5)
(5, 1) (5, 2) (5, 3) (5, 4) (5, 5)
(6, 1) (6, 2) (6, 3) (6, 4) (6, 5)


3
11111
01111
00*11
00001
00000
10110
01*11
10111
01001
00000
01011
110*1
01110
01010
00100
*/
