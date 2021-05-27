#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1010;

//vector<vector<int>> Map;

int main()
{
    // freopen("Aldata.out", "w", stdout);

    // int n = 11;
    // printf("%d\n", n);
    // for (int i = 1; i <= n * (n - 1); i++)
    //     printf("%d ", rand() % 500 + 1);

    freopen("data.out", "w", stdout);

    for (int i = 0; i <= 11; i++)
    {
        for (int j = 0; j <= 11; j++)
        {
            if (i == 11 - j)
                printf("[%d, %d, %d],\n", i, j, 150);
            else
                printf("[%d, %d, %d],\n", i, j, 0);
        }
    }

    // for (int i = 100; i <= 10000; i += 100)
    //     printf("%d\n", i * 100 * 1000 / 10000000 + rand() % 5 + i / 30);
    // freopen("1.in", "w", stdout);

    // srand(time(0));

    // int n = 1000, m = 1000;
    // printf("%d %d\n", n, m);

    // int cnt = 1;
    // for (int i = 1; i <= 1000; i++)
    // {
    //     for (int j = 1; j <= 1000; j++)
    //         printf("%d ", cnt++);
    //     puts("");
    // }
    // printf("%d\n", cnt - 1001);

    return 0;
}
