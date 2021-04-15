#include <bits/stdc++.h>

using namespace std;

int A[100000];
int main()
{
    freopen("1.in", "w", stdout);

    srand(time(0));

    // int m = 21000;
    // printf("%d\n", m);
    // while (m--)
    // {
    //     int n1 = rand() % 100, n2 = rand() % 100;

    //     printf("%d %d\n", n1, n2);

    //     for (int i = 1; i <= n1; i++)
    //         printf("%d ", rand() % 300);

    //     puts("");
    //     for (int i = 1; i <= n2; i++)
    //         printf("%d ", rand() % 300);
    //     puts("");
    // }

    int m = 10000;
    printf("%d\n", m);
    while (m--)
    {
        int n1 = 100, n2 = 100;

        printf("%d %d\n", n1, n2);

        for (int i = 1; i <= n1; i++)
            printf("%d ", rand() % 300);

        puts("");
        for (int i = 1; i <= n2; i++)
            printf("%d ", rand() % 300);
        puts("");
    }
    return 0;
}
