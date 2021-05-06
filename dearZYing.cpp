#include <stdio.h>
#include <math.h>
int t = 0, board[1000][1000];
int cnt = 0;
void ChessBoard(int tr, int tc, int dr, int dc, int size)
{
    cnt++;
    int nowp = cnt;
    printf("%d %d %d %d %d %d %d\n", cnt, tr, tc, tr + size - 1, tc + size - 1, dr, dc);
    int s, nCount; //nCount表示本次覆盖所用L型骨牌的编号
    if (size == 1)
        return;                                                 //棋盘只有一个方格且是特殊方格
    nCount = ++t;                                               // L型骨牌编号
    s = size / 2;                                               // 划分棋盘
    if (dr < tr + s && dc < tc + s)                             //特殊方格在左上角子棋盘中
        printf("%d - > ", nowp), ChessBoard(tr, tc, dr, dc, s); //递归处理子棋盘
    else
    { //用 nCount号L型骨牌覆盖右下角，再递归处理子棋盘
        board[tr + s - 1][tc + s - 1] = nCount;
        printf("%d - > ", nowp), ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
    }
    if (dr < tr + s && dc >= tc + s)                                //特殊方格在右上角子棋盘中
        printf("%d - > ", nowp), ChessBoard(tr, tc + s, dr, dc, s); //递归处理子棋盘
    else
    { //用 nCount号L型骨牌覆盖左下角，再递归处理子棋盘
        board[tr + s - 1][tc + s] = nCount;
        printf("%d - > ", nowp), ChessBoard(tr, tc + s, tr + s - 1, tc + s, s);
    }
    if (dr >= tr + s && dc < tc + s)                                //特殊方格在左下角子棋盘中
        printf("%d - > ", nowp), ChessBoard(tr + s, tc, dr, dc, s); //递归处理子棋盘
    else
    { //用 nCount号L型骨牌覆盖右上角，再递归处理子棋盘
        board[tr + s][tc + s - 1] = nCount;
        printf("%d - > ", nowp), ChessBoard(tr + s, tc, tr + s, tc + s - 1, s);
    }
    if (dr >= tr + s && dc >= tc + s)                                   //特殊方格在右下角子棋盘中
        printf("%d - > ", nowp), ChessBoard(tr + s, tc + s, dr, dc, s); //递归处理子棋盘
    else
    { //用 nCount号L型骨牌覆盖左上角，再递归处理子棋盘
        board[tr + s][tc + s] = nCount;
        printf("%d - > ", nowp), ChessBoard(tr + s, tc + s, tr + s, tc + s, s);
    }
}
int main()
{
    int n, k; //n=2^k
    scanf("%d", &k);
    n = pow(2, k);
    int x, y;
    scanf("%d%d", &x, &y);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == x && j == y)
                board[i][j] = 0;
            else
                board[i][j] = 1;
        }
    ChessBoard(1, 1, x, y, n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%3d", board[i][j]);
        }
        puts("");
    }
    return 0;
}

/*
3
4 5

2
2 3
*/
