// #include <bits/stdc++.h>

// using namespace std;

// const int MaxN = 100010;
// const int MaxM = 1000010;

// int num = 0;
// int head[MaxN];
// struct Edge
// {
//     int next, to, val;
// };
// Edge edge[MaxM];

// vector<Edge> A[MaxN];

// void AddEdge(int x, int y)
// {
//     edge[++num].next = head[x];
//     edge[num].to = y;
//     head[x] = num;
// }

// bool vis[MaxN];
// int dis[MaxN];

// void Dijkstra(int n, int start)
// {
//     // vis[i]为 true 表示 i 点在CloseList中
//     // vis[i]为 false 表示 i 点在OpenList中
//     memset(vis, false, sizeof(vis));
//     memset(dis, 0x3f, sizeof(dis));

//     dis[start] = 0;
//     for (int i = 0; i < n; i++)
//     {
//         // 先找到 OpenList 中 dis 最小的点
//         int current = 0, minDis = 0x3f3f3f3f;
//         for (int j = 1; j <= n; j++)
//         {
//             if (!vis[j] && dis[j] < minDis)
//             {
//                 current = j;
//                 minDis = dis[j];
//             }
//         }

//         // 枚举current的每一条出边
//         for (int j = 0; j < A[current].size(); j++)
//         {
//             int dest = A[current][j].to;
//             int val = A[current][j].val;

//             if (dis[dest] > dis[current] + val)
//                 dis[dest] = dis[current] + val;
//         }

//         vis[current] = true; // 将current转移到 CloseList
//     }
// }

// void Solve()
// {
//     srand(time(0));

//     int n = 100000, m = 1000000;
//     // scanf("%d%d", &n, &m);

//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         u = rand() % n, v = rand() % n;
//         // A[u].push_back(v);
//         AddEdge(u, v);
//     }

//     clock_t start, end;
//     start = clock();
//     int temp;
//     for (int k = 0; k < 1000; k++)
//     {
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 0; j < A[i].size(); j++)
//             {
//                 // temp = A[i][j];
//             }
//         }
//     }
//     end = clock();

//     cout << "Use vector : " << (end - start) / CLOCKS_PER_SEC << endl;

//     start = clock();
//     for (int k = 0; k < 1000; k++)
//     {
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = head[i]; j; j = edge[j].next)
//             {
//                 // 起点：i
//                 // 终点：edge[j].to;
//             }
//         }
//     }
//     end = clock();

//     cout << "Use LinkedList : " << (end - start) / CLOCKS_PER_SEC << endl;
// }

// int main()
// {
//     Solve();

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

const int MaxN = 100010;
const int INF = 0x3f3f3f3f;

typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> q;

int dis[MaxN];
bool vis[MaxN];

vector<pii> A[MaxN];

void Dijkstra(int n, int start)
{
    memset(dis, 0x3f, sizeof(dis));
    dis[start] = 0;

    q.push(make_pair(dis[start], start));
    while (!q.empty())
    {
        int x = q.top().second;
        q.pop();
        if (vis[x])
            continue;
        vis[x] = 1;

        for (int i = 0; i < A[x].size(); i++)
        {
            int to = A[x][i].first, val = A[x][i].second;
            if (dis[to] > dis[x] + val)
            {
                dis[to] = dis[x] + val;
                q.push(make_pair(dis[to], to));
            }
        }
    }
}

enum Gender_t
{
    male,
    female
};

struct Student
{
    int Id;
    string Name;
    int Age;
    Gender_t Gender;
};

bool cmp(Student a, Student b)
{
    // return a.Age > b.Age;
    if (a.Age > b.Age)
        return true;
    return false;
}

void Solve()
{
    // int n, m, start;
    // scanf("%d%d%d", &n, &m, &start);
    // for (int i = 1; i <= m; i++)
    // {
    //     int u, v, val;
    //     scanf("%d%d%d", &u, &v, &val);
    //     A[u].push_back(make_pair(v, val));
    // }

    // Dijkstra(n, start);

    // for (int i = 1; i <= n; i++)
    //     printf("%d ", dis[i]);

    int A[10] = {2, 4, 8, 9, 12, 15, 20, 24, 25, 31};

    auto it = lower_bound(A, A + 10, 32);
    printf("%d", it - A);

    int n;
    Student students[10];

    sort(students, students + n, cmp);
}

int main()
{
    Solve();

    return 0;
}
/*
8 15
4 3
5 2
1 5
7 5
8 5
1 6
3 7
4 8
5 7
8 4
3 1
4 1
3 8
5 4
8 6
*/

/*
dataGenerator:

srand(time(0));

int n = 8, m = 15;

for (int i = 0; i < m; i++)
{
    int u = 0, v = 0;
    while (u == v || A[u][v])
    {
        u = rand() % 8 + 1;
        v = rand() % 8 + 1;
    }

    A[u][v] = 1;
    printf("%d %d\n", u, v);
}


\ 1 2 3 4 5 6 7 8
1 0 0 0 0 1 1 0 0
2 0 0 0 0 0 0 0 0
3 1 0 0 0 0 0 1 1
4 1 0 1 0 0 0 0 1
5 0 1 0 1 0 0 1 0
6 0 0 0 0 0 0 0 0
7 0 0 0 0 1 0 0 0
8 0 0 0 1 1 1 0 0

1: 5 6
2:
3: 7 1 8
4: 3 8 1
5: 2 7 4
6:
7: 5
8: 5 4 6
*/
