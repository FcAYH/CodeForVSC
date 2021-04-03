#include <stdio.h>

void Solve()
{
    printf("Input an integer number:\n");

    int n;
    scanf("%d", &n);

    !(n % 2) ? printf("%d is an even number\n", n) : printf("%d is an odd number\n", n);
}

int main()
{
    Solve();

    while (1)
        ;

    return 0;
}
