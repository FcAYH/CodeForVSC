#include <stdio.h>

long int work(int x, int y)
{
    long int ans = 0, Modify = 1;
    for (int i = 1; i <= x; i++)
        Modify *= i;
    for (int i = x; i <= y; i++)
        ans += Modify, Modify *= i + 1;
    return ans;
}

void Solve()
{
    printf("Please input m,n");
    int m, n;
    scanf("%d,%d", &m, &n);

    long int sum = 0;
    sum = work(m, n);
    printf("\nsum = %ld\n", sum);
}

int main()
{
    Solve();

    return 0;
}
