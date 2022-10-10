// #include <bits/stdc++.h>

// using namespace std;

// const int MaxN = 1010;

// int n;
// int nums = 0;
// int relate[MaxN][MaxN];
// int vis[MaxN];
// int pre[MaxN];

// void dfs(int x, int fa)
// {
//     vis[x] = 1;
//     for (int i = 0; i < n; i++)
//     {
//         if (relate[x][i])
//         {
//             if (vis[i] == 0)
//             {
//                 pre[i] = x;
//                 dfs(i, x);
//             }
//             else if (vis[i] == 1)
//             {
//                 int temp = x;
//                 int count = 1;
//                 while (temp != i)
//                 {
//                     count++;
//                     cout << temp << " <- ";
//                     temp = pre[temp];
//                 }
//                 cout << i << " : " << count << endl;
//                 if (count == 4)
//                     nums++;
//             }
//         }
//     }
//     vis[x] = 2;
// }

// void Solve()
// {
//     scanf("%d", &n);

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             scanf("%d", &relate[i][j]);
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (vis[i] == 0)
//             dfs(i, -1);
//     }

//     printf("ans: %d", nums);
// }

// int main()
// {
//     Solve();

//     return 0;
// }

// /*
// 7
// 0 0 0 0 1 0 0
// 0 0 1 0 0 0 0
// 1 0 1 0 0 0 0
// 0 0 0 0 1 1 0
// 0 1 0 0 0 0 1
// 0 0 0 0 0 0 1
// 0 0 1 0 0 0 0
// */
#include <iostream>
#include <cstring>
using namespace std;
int Next[1000001]; //指向下一结点的指针
int vis[1000001];  //对每个结点进行不同的标记
int ans, n, ringID, p;
void search()
{
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i] > 0)
            continue;
        p = i;
        ++ringID;           //对每一种环进行一种不同的标记，新的起点必须更换新的染色
        while (vis[p] == 0) //当前结点未被染色
        {
            vis[p] = ringID;      //染色
            p = Next[p];          //指向下一个点
            if (vis[p] == ringID) //下一个点的颜色和当前染色相同,则说明存在一个环
                ++ans;
        }
    }
}
int main()
{
    // freopen("in.txt","r",stdin);
    while (scanf("%d", &n) != EOF)
    {
        ans = 0;
        ringID = 1;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &Next[i]);
            if (Next[i] == i)
            {
                vis[i] = ringID++; //先对自环进行预处理
                ans++;
            }
        }
        search();
        printf("%d/n", ans);
    }
    return 0;
}
/*
7 10
1 5
2 3
3 4
3 1
4 5
4 6
5 2
5 7
6 7
7 3
*/
