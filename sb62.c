#include <stdio.h>

void Solve()
{
    int a[11];
    for (int i = 1; i <= 10; i++)
        scanf("%d", &a[i]);

    int b[11];

    for (int i = 1; i <= 9; i++)
        b[i] = a[i] + a[i + 1];

    for (int i = 1; i <= 9; i++)
        printf("%4d", b[i]);
}

int main()
{
    Solve();

    return 0;
}
