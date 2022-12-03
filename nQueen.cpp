#include <bits/stdc++.h>

using namespace std;

const int MaxN = 12;

int counter = 0;
bool buffer[MaxN][MaxN];
bool vis[3][MaxN << 1 | 1]; // 0 -> col, 1 -> left, 2 -> right

void PrintSolution(int n, int index)
{
    printf("Index: %d\n", index);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", buffer[i][j]);
        }
        puts("");
    }
}

void NQueens(int n, int current)
{
    if (current == n) // 记录答案
    {
        counter++;
        // 输出答案
        // PrintSolution(n, counter);
        return;
    }

    int row = current;
    for (int col = 0; col < n; col++)
    {
        // 第col列不存在Queen，第col+row个向左斜线不存在Queen，第col-row+n-1个向右斜线不存在Queen
        if (!vis[0][col] && !vis[1][col + row] && !vis[2][col - row + n - 1])
        {
            buffer[row][col] = true; // 在row，col位置放置Queen
            vis[0][col] = true, vis[1][col + row] = true, vis[2][col - row + n - 1] = true;

            NQueens(n, current + 1);

            // 回溯
            vis[0][col] = false, vis[1][col + row] = false, vis[2][col - row + n - 1] = false;
            buffer[row][col] = false;
        }
    }
}

void Solve()
{
    int n;
    scanf("%d", &n);

    NQueens(n, 0);

    printf("Sum: %d\n", counter);
}

int main()
{
    Solve();

    return 0;
}

/*
||0|1|2|3|4|5|6|7|
|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|
|0|0|1|2|3|4|5|6|7|
|1|-1|0|3|4|5|6|7|8|
|2|-2|-1|4|5|6|7|8|9|
|3|-3|4|5|6|7|8|9|10|
|4|-4|5|6|7|8|9|10|11|
|5|-5|6|7|8|9|10|11|12|
|6|-6|7|8|9|10|11|12|13|
|7|-7|8|9|10|11|12|13|14|

*/
