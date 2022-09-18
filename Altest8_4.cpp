#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int jx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int jy[] = {1, 0, -1, 0, 1, -1, 1, -1};
char a[201][201];
int map[201][201];
int v[201][201];
int n, m;
int nowRoc, nowCol, nowRoc1, nowCol1;
int cnt;

struct node
{
    int x;
    int y;
};

int BFS(int row, int col)
{
    nowRoc = 0;
    nowCol = 0;
    int count = 0;
    struct node t, f;
    queue<node> q;
    t.x = row;
    t.y = col;
    nowRoc1 = t.x;
    nowCol1 = t.y;
    q.push(t);
    v[t.x][t.y] = 1;
    count++;
    while (!q.empty())
    {
        t = q.front();

        int size = q.size();

        for (int i = 1; i <= size; i++)
        {
            node t = q.front();
            printf("(%d %d) ", t.x, t.y);
            q.pop();
            q.push(t);
        }
        puts("");

        q.pop();
        int pf = 0;
        for (int i = 0; i < 8; i++)
        {
            if (pf >= 1)
            {
                break;
            }
            f.x = t.x + jx[i];
            f.y = t.y + jy[i];
            if (f.x >= 0 && f.x < n && f.y >= 0 && f.y < m && map[f.x][f.y] == 1 && v[f.x][f.y] == 0)
            {
                if (i == 1 || i == 2 || i == 3 || i == 0)
                {
                    q.push(f);
                    v[f.x][f.y] = 1;
                    nowRoc = f.x;
                    nowCol = f.y;
                    count++;
                    pf++;
                }
                else if (i == 4 && a[f.x / 2][f.y / 2] != '/')
                {
                    q.push(f);
                    v[f.x][f.y] = 1;
                    nowRoc = f.x;
                    nowCol = f.y;
                    count++;
                    pf++;
                }
                else if (i == 5 && a[f.x / 2][f.y / 2] != '\\')
                {
                    q.push(f);
                    v[f.x][f.y] = 1;
                    nowRoc = f.x;
                    nowCol = f.y;
                    count++;
                    pf++;
                }
                else if (i == 6 && a[f.x / 2][f.y / 2] != '\\')
                {
                    q.push(f);
                    v[f.x][f.y] = 1;
                    nowRoc = f.x;
                    nowCol = f.y;
                    count++;
                    pf++;
                }
                else if (i == 7 && a[f.x / 2][f.y / 2] != '/')
                {
                    q.push(f);
                    v[f.x][f.y] = 1;
                    nowRoc = f.x;
                    nowCol = f.y;
                    count++;
                    pf++;
                }
            }
        }
    }
    return count;
}

int main()
{
    scanf("%d%d", &m, &n);
    cnt = 0;
    int pflag = 0;
    memset(v, 0, sizeof(v));
    for (int i = 0; i < n; i++)
    {
        scanf("%s", a[i]);
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '/')
            {
                map[2 * i][2 * j] = 1;
                map[2 * i][2 * j + 1] = 0;
            }
            else if (a[i][j] == '\\')
            {
                map[2 * i][2 * j] = 0;
                map[2 * i][2 * j + 1] = 1;
            }
        }
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '/')
            {
                map[2 * i + 1][2 * j] = 0;
                map[2 * i + 1][2 * j + 1] = 1;
            }
            else if (a[i][j] == '\\')
            {
                map[2 * i + 1][2 * j] = 1;
                map[2 * i + 1][2 * j + 1] = 0;
            }
        }
    }
    n = 2 * n;
    m = 2 * m;
    int maxx = 0;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 1 && v[i][j] == 0)
            {
                flag = 0;
                int pk = BFS(i, j);
                for (int v1 = 0; v1 < 8; v1++)
                {
                    int x1 = nowRoc + jx[v1];
                    int y1 = nowCol + jy[v1];
                    if (nowRoc1 == x1 && nowCol1 == y1)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1 && pk >= 4)
                {
                    pflag = 1;
                    cnt++;
                    if (pk > maxx)
                    {
                        maxx = pk;
                    }
                }
            }
        }
    }
    if (pflag == 1)
    {
        printf("%d Cycles; the longest has length %d.\n\n", cnt, maxx);
    }
    else
    {
        printf("There are no cycles.\n\n");
    }
    return 0;
}
/*
4 4
/\//
\/\\
////
\///
4 4

*/
