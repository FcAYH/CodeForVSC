#include <bits/stdc++.h>

using namespace std;

const int MaxN = 20;

struct Point
{
    int x, y, z;
    Point(int x, int y, int z) : x(x), y(y), z(z) {}
};

int k, n, m;
char cube[MaxN][MaxN][MaxN];
int vis[MaxN][MaxN][MaxN];

int dx[] = {-1, 0, 1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

int Bfs(int x, int y)
{
    Point startPoint(x - 1, y - 1, 0);
    queue<Point> points;
    int ans = 1;
    vis[startPoint.x][startPoint.y][startPoint.z] = 1;

    points.push(startPoint);
    while (points.size() > 0)
    {
        Point current = points.front();
        points.pop();

        for (int i = 0; i < 6; i++)
        {
            Point attempt(current.x + dx[i], current.y + dy[i], current.z + dz[i]);

            if (attempt.x < 0 || attempt.x >= n || attempt.y < 0 || attempt.y >= m || attempt.z < 0 || attempt.z >= k)
                continue;

            if (cube[attempt.z][attempt.x][attempt.y] != '#' && !vis[attempt.x][attempt.y][attempt.z])
            {
                // printf("%d %d %d\n", attempt.x, attempt.y, attempt.z);
                points.push(attempt);
                vis[attempt.x][attempt.y][attempt.z] = 1;
                ans++;
            }
        }
    }

    return ans;
}

void Solve()
{
    scanf("%d%d%d", &k, &n, &m);

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%s", cube[i][j]);
        }
    }

    int x, y;
    scanf("%d%d", &x, &y);

    printf("%d", Bfs(x, y));
}

int main()
{
    Solve();

    return 0;
}

/*
3 3 3

.#.
###
##.

.##
###
##.

...
...
...

2 2
*/
