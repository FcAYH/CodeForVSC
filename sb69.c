#include <stdio.h>

void Solve()
{
    int cnt = 1, sum = 0;
    while (sum < 1000000)
    {
        sum += cnt * cnt * cnt;
        cnt++;
    }
    printf("count = %d\n", cnt);
}

int main()
{
    Solve();

    return 0;
}
