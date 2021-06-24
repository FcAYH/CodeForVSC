//8.3代码
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <stack>
#include <map>
#include <queue>
#include <climits>

using namespace std;
const int MAX = 110;
char my_map[MAX][MAX];
int n, m, my_book[MAX][MAX] = {0}, Mx, My, Px, Py, Kx, Ky, mov[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct node
{
    int x, y, cnt;
};

bool judge(node q)
{
    if (my_book[q.x][q.y])
        return false;
    if (my_map[q.x][q.y] == '#')
        return false;
    if (q.x < 0 || q.x >= n || q.y < 0 || q.y >= m)
        return false;
    return true;
}

int bfs1()
{
    node q1, q2;
    q1.x = Mx, q1.y = My, q1.cnt = 0;
    my_book[Mx][My] = 1;
    queue<node> Q;
    Q.push(q1);
    while (!Q.empty())
    {
        q1 = Q.front();
        if (my_map[q1.x][q1.y] == 'B')
            return q1.cnt - 1;
        for (int i = 0; i < 4; ++i)
        {
            q2 = q1;
            q2.x = q1.x + mov[i][0];
            q2.y = q1.y + mov[i][1];
            q2.cnt = q1.cnt + 1;
            if (judge(q2))
            {
                Q.push(q2);
                my_book[q2.x][q2.y] = 1;
            }
        }
        Q.pop();
    }
    return 0;
}

int bfs2()
{
    memset(my_book, 0, sizeof(my_book));
    node q1, q2;
    q1.x = Px, q1.y = Py, q1.cnt = 0;
    my_book[Mx][My] = 1;
    queue<node> Q;
    Q.push(q1);
    while (!Q.empty())
    {
        q1 = Q.front();
        if (my_map[q1.x][q1.y] == 'T')
            return q1.cnt;
        for (int i = 0; i < 4; ++i)
        {
            q2 = q1;
            q2.x = q1.x + mov[i][0];
            q2.y = q1.y + mov[i][1];
            q2.cnt = q1.cnt + 1;
            if (judge(q2))
            {
                Q.push(q2);
                my_book[q2.x][q2.y] = 1;
            }
        }
        Q.pop();
    }
    return 0;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> my_map[i];
        for (int j = 0; j < m; ++j)
        {
            if (my_map[i][j] == 'S')
            {
                Mx = i, My = j;
            }
            if (my_map[i][j] == 'B')
            {
                Px = i, Py = j;
            }
            if (my_map[i][j] == 'T')
            {
                Kx = i, Ky = j;
            }
        }
    }
    int t1 = bfs1(); //机器人到箱子
    if (t1 == 0)
    {
        cout << "No Solution!" << endl;
        return 0;
    }
    int t2 = bfs2(); //箱子到目标
    if (t2 == 0)
    {
        cout << "No Solution!" << endl;
    }
    else
    {
        cout << t2 << endl;
    }
}
/*
7 11
###########
#T##......#
#.#.#..####
#....B....#
#.######..#
#.....S...#
###########
*/
