#include <stdio.h>

void Solve()
{
    int x = 11;

    while (1)
    {
        if (x % 5 == 1 && x % 6 == 5 && x % 7 == 4 && x % 11 == 10)
            break;
        x++;
    }
    printf("x = %d\n", x);
}

int main()
{
    Solve();

    return 0;
}
