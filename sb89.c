#include <stdio.h>

void Solve()
{
    printf("This program sums a series of integers.\n");
    printf("Enter integers (0 to terminate):");

    int x, sum = 0;
    scanf("%d", &x);
    while (x)
    {
        sum += x;
        scanf("%d", &x);
    }

    printf("The sum is: %d\n", sum);
}

int main()
{
    Solve();

    return 0;
}
