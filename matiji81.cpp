#include <bits/stdc++.h>

using namespace std;

void Solve()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);

        if (!(n % 4))
        {
            printf("%d", n / 4);
        }
        else if (n % 4 == 2)
        {
            if (n / 4 >= 1)
            {
                printf("%d", n / 4);
            }
            else
            {
                printf("%d", -1);
            }
        }
        else if (n % 4 == 1)
        {
            if (n / 4 >= 2)
            {
                printf("%d", n / 4 - 1);
            }
            else
            {
                printf("%f", -1);
            }
        }
        else
        {
            if (n / 4 >= 3)
            {
                printf("%d", n / 4 - 1);
            }
            else
            {
                printf("%d", -1);
            }
        }

        puts("");
    }
}

int main()
{
    Solve();

    return 0;
}
