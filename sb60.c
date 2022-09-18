#include <stdio.h>

void Solve()
{
    printf("Input a number:");
    int n, count = 0;
    int sum = 0;

    scanf("%d", &n);
    while (n != 0)
    {
        if (n > 0)
            sum += n, count++;

        printf("Input a number:");
        scanf("%d", &n);
    }

    printf("sum = %d, count = %d\n", sum, count);
}

int main()
{
    Solve();

    return 0;
}
