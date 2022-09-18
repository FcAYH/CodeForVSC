#include <bits/stdc++.h>

using namespace std;

const int Maxn = 30;

int m, n;
int position[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int ans_arr[Maxn][Maxn], ans;

struct Node
{
    int robotPos[Maxn][Maxn];
    int roomWatched[Maxn][Maxn];
    int i, j;
    int robotNum, roomNum;
};

struct cmp
{
    bool operator()(Node a, Node b)
    {
        return a.roomNum > b.roomNum;
    }
};

priority_queue<Node, vector<Node>, cmp> q;

Node Init(Node node)
{
    memset(node.robotPos, 0, sizeof(node.robotPos));
    memset(node.roomWatched, 0, sizeof(node.roomWatched));

    node.i = 1;
    node.j = 1;

    node.robotNum = 0;
    node.roomNum = 0;

    for (int i = 0; i <= m + 1; i++)
        node.roomWatched[i][0] = node.roomWatched[i][m + 1] = 1;

    for (int i = 0; i <= n + 1; i++)
        node.roomWatched[0][i] = node.roomWatched[n + 1][i] = 1;
    return node;
}

void SetRobot(Node p, int x, int y)
{
    Node node;
    node = Init(node);
    node.i = p.i;
    node.j = p.j;
    node.roomNum = p.roomNum;
    memcpy(node.robotPos, p.robotPos, sizeof(p.robotPos));
    memcpy(node.roomWatched, p.roomWatched, sizeof(p.roomWatched));

    node.robotPos[x][y] = 1;
    node.robotNum = p.robotNum + 1;

    for (int d = 0; d < 5; d++)
    {
        int pos_x = x + position[d][0];
        int pos_y = y + position[d][1];
        node.roomWatched[pos_x][pos_y]++;

        if (node.roomWatched[pos_x][pos_y] == 1)
        {
            node.roomNum++;
        }
    }

    while (node.i <= m && node.roomWatched[node.i][node.j])
    {
        node.j++;

        if (node.j > n)
            node.i++, node.j = 1;
    }

    q.push(node);
    return;
}

void Solve()
{
    scanf("%d%d", &m, &n);

    ans = m * n / 3 + 2;

    Node node;
    node = Init(node);

    q.push(node);

    while (!q.empty())
    {
        Node p = q.top();

        q.pop();

        if (p.roomNum < m * n)
        {
            if (p.i < m)
                SetRobot(p, p.i + 1, p.j);

            if ((p.i == m && p.j == n) || p.roomWatched[p.i][p.j + 1] == 0)
                SetRobot(p, p.i, p.j);

            if (p.j < n && (p.roomWatched[p.i][p.j + 1] == 0 || p.roomWatched[p.i][p.j + 2] == 0))
                SetRobot(p, p.i, p.j + 1);
        }

        else if (p.roomNum >= m * n)
        {
            if (p.robotNum < ans)
            {
                ans = p.robotNum;

                memcpy(ans_arr, p.robotPos, sizeof(p.robotPos));
            }
        }
    }

    printf("%d\n", ans);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%d ", ans_arr[i][j]);
        printf("\n");
    }
}

int main()
{
    Solve();

    return 0;
}
