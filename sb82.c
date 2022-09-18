#include <stdio.h>

void Solve()
{
    int sum = 1;
    for (int i = 9; i >= 1; i--)
        sum = (sum + 1) << 1;
    printf("sum=%d", sum);
}

int main()
{
    Solve();

    return 0;
}
