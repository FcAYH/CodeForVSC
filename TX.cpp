#include <bits/stdc++.h>

using namespace std;

const int MaxRow = 100;
const int MaxCol = 100;

void Solve()
{
    int row, col;

    scanf("%d%d", &row, &col);

    int array[MaxRow][MaxCol];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &array[i][j]);
        }
        return;
    }

    if (row == 1)
    {
        for (int i = 0; i < col; i++)
        {
            printf("%d ", array[0][i]);
        }
        return;
    }

    if (col == 1)
    {
        for (int i = 0; i < row; i++)
        {
            printf("%d ", array[i][0]);
        }
    }

    // 一圈一圈打印
    for (int i = 0; i < row / 2; i++)
    {
        if (i >= col / 2)
            break;

        // 上
        for (int j = i; j < col - i; j++)
            printf("%d ", array[i][j]);

        // 右
        for (int j = i + 1; j < row - i; j++)
            printf("%d ", array[j][col - i - 1]);

        // 下
        for (int j = col - i - 2; j >= i; j--)
            printf("%d ", array[row - i - 1][j]);

        // 左
        for (int j = row - i - 2; j > i; j--)
            printf("%d ", array[j][i]);
    }

    // TODO: row != col 的情况
    // TODO: 奇数的时候加上中间的

    if (col & 1 && !(row & 1)) // row是奇数
    {
        for (int i = row / 2 - 1; i < row - row / 2 + 1; i++)
            printf("%d ", array[i][col / 2]);
    }
    else if (row & 1 && !(col & 1))
    {
        for (int j = col / 2 - 1; j < col - col / 2 + 1; j++)
            printf("%d ", array[row / 2][j]);
    }
    else if (col & 1 && row & 1)
    {
        printf("%d ", array[row / 2][col / 2]);
    }
}

int main()
{
    Solve();

    return 0;
}

/*
examples:
4 4
 1  2  3  4
 5  6  7  8
 9 10 11 12
13 14 15 16


4 2
1 2
3 4
5 6
7 8


5 2
1 2
3 4
5 6
7 8
9 10

4 3
 1  2  3
 4  5  6
 7  8  9
10 11 12

3 4
 1  2  3  4
 5  6  7  8
 9 10 11 12

3 3
1 2 3
4 5 6
7 8 9

1 5
1 2 3 4 5

5 1
1
2
3
4
5
*/
