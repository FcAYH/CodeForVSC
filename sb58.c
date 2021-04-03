#include <stdio.h>

void Solve()
{
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            for (int k = 1; k <= 5; k++)
                if (i != j && i != k && j != k)
                    printf("%d,%d,%d\n", i, j, k);
}

int main()
{
    Solve();

    return 0;
}
