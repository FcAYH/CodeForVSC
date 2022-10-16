#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n, r, c, sx, sy;
char Order[1010];
char dt[51][51];
char Map[51][51];
bool vis[51][51][1010];
queue<int> Qx;
queue<int> Qy;
queue<int> Qord;
void bfs()
{
    Qx.push(sx);
    Qy.push(sy);
    Qord.push(1);
    vis[sx][sy][1] = 1;
    while (!Qx.empty())
    {
        int nx = Qx.front(), ny = Qy.front(), no = Qord.front();
        Qx.pop();
        Qy.pop();
        Qord.pop();
        char next = Order[no];
        // printf("%d %d %d\n",nx,ny,no);
        switch (next)
        {
        case 'E':
        {
            int tol = ny + 1;
            while (dt[nx][tol] != 'X' && tol <= c)
            {
                if (vis[nx][tol][no + 1])
                {
                    tol++;
                    continue;
                }
                if (no == n)
                {
                    // printf("<%d %d>\n",nx,tol);
                    Map[nx][tol] = '*';
                    tol++;
                    continue;
                }
                vis[nx][tol][no + 1] = 1;
                Qx.push(nx);
                Qy.push(tol);
                Qord.push(no + 1);
                tol++;
            }
            break;
        }
        case 'N':
        {
            int tol = nx - 1;
            while (dt[tol][ny] != 'X' && tol >= 1)
            {
                if (vis[tol][ny][no + 1])
                {
                    tol--;
                    continue;
                }
                if (no == n)
                {
                    // printf("<%d %d>\n",tol,ny);
                    Map[tol][ny] = '*';
                    tol--;
                    continue;
                }
                vis[tol][ny][no + 1] = 1;
                Qx.push(tol);
                Qy.push(ny);
                Qord.push(no + 1);
                tol--;
            }
            break;
        }
        case 'W':
        {
            int tol = ny - 1;
            while (dt[nx][tol] != 'X' && tol >= 1)
            {
                if (vis[nx][tol][no + 1])
                {
                    tol--;
                    continue;
                }
                if (no == n)
                {
                    // printf("<%d %d>\n",nx,tol);
                    Map[nx][tol] = '*';
                    tol--;
                    continue;
                }
                vis[nx][tol][no + 1] = 1;
                Qx.push(nx);
                Qy.push(tol);
                Qord.push(no + 1);
                tol--;
            }
            break;
        }
        case 'S':
        {
            int tol = nx + 1;
            while (dt[tol][ny] != 'X' && tol <= r)
            {
                if (vis[tol][ny][no + 1])
                {
                    tol++;
                    continue;
                }
                if (no == n)
                {
                    // printf("<%d %d>\n",tol,ny);
                    Map[tol][ny] = '*';
                    tol++;
                    continue;
                }
                vis[tol][ny][no + 1] = 1;
                Qx.push(tol);
                Qy.push(ny);
                Qord.push(no + 1);
                tol++;
            }
            break;
        }
        }
    }
}
void print()
{
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            printf("%c", Map[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; i++)
    {
        cin >> (dt[i] + 1);
    }
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (dt[i][j] == '*')
            {
                sx = i, sy = j;
                Map[i][j] = '.';
            }
            else
                Map[i][j] = dt[i][j];
        }
    }
    // print();
    scanf("%d", &n);
    char dir[10];
    for (int i = 1; i <= n; i++)
    {
        cin >> (dir + 1);
        if (dir[1] == 'N')
            Order[i] = 'N';
        if (dir[1] == 'S')
            Order[i] = 'S';
        if (dir[1] == 'E')
            Order[i] = 'E';
        if (dir[1] == 'W')
            Order[i] = 'W';
    }
    bfs();
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            printf("%c", Map[i][j]);
        }
        cout << endl;
    }
    return 0;
}
/*
4 4
..X.
X...
...X
..*.
2
North
South

*/
