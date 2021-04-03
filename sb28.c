#include <stdio.h>

void Solve()
{
    int cnt = 0;

    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            for (int k = 1; k <= 5; k++)
            {
                if (i != j && i != k && j != k)
                    printf("%2d:%d,%d,%d\n", ++cnt, i, j, k);
            }
        }
    }
}

int main()
{
    Solve();

    while (1)
        ;

    return 0;
}
