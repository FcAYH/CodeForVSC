#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1010;

//vector<vector<int>> Map;

int main()
{
    srand(time(0));

    freopen("data3.in", "w", stdout);

    int length = 999;

    for (int i = 1; i <= length - 1; i += 2)
    {
        int x = rand() % 10;
        printf("%d", x);
        int ope = rand() % 2;

        if (i != 997)
        {
            if (ope == 0)
                printf("+");
            else
                printf("-");
        }
    }
    printf("=");

    return 0;
}
