// #include <bits/stdc++.h>

// using namespace std;

// const int Maxn = 1010;

// int tol[Maxn];
// int tArray[Maxn];

// inline int cmp(int x, int y)
// {
//     return x < y;
// }

// void Solve()
// {
//     int m, n;
//     scanf("%d%d", &m, &n);
//     for (int i = 1; i <= m; i++)
//     {
//         scanf("%d", &tol[i]);
//         tArray[i] = tol[i];
//     }

//     sort(tArray + 1, tArray + 1 + m, cmp);

//     int ans = 0;
//     int solved = 0, nowp = 1;
//     while (true)
//     {
//         while (tol[nowp] != tArray[solved + 1])
//         {
//             nowp++;
//             if (nowp == m + 1)
//                 nowp = 1;
//         }
//         if (tol[nowp] == tArray[solved + 1])
//         {
//             solved++;
//             if (nowp == n)
//             {
//                 ans = solved;
//                 break;
//             }
//         }
//     }

//     printf("%d", ans);
// }

// int main()
// {
//     Solve();

//     return 0;
// }
#include <iostream>
using namespace std;
int n, m;
int Ans[1010];
struct pro
{
    int x;
    int id;
} f[1010];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &f[i].x);
        f[i].id = i;
    }
    int ans = 1;
    while (n)
    {
        int pos = 1, Min = f[1].x;
        for (int i = 2; i <= n; i++)
            if (f[i].x < Min)
            {
                pos = i;
                Min = f[i].x;
            }
        if (pos == 1)
        {
            Ans[f[1].id] = ans;
            for (int i = 1; i < n; i++)
                f[i] = f[i + 1];
            n--;

            ans++;
        }
        else
        {
            pro temp = f[1];
            for (int i = 1; i < n; i++)
                f[i] = f[i + 1];
            f[n] = temp;
        }
    }
    cout << Ans[m];
    return 0;
}

/*
4 3
1 2 3 4 

7 3
8 7 8 9 1 2 8 
*/
