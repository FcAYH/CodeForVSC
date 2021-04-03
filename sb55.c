#include <stdio.h>

void Solve()
{
    printf("Please enter n:");
    int n;
    scanf("%d", &n);
    while (n > 0)
    {
        printf("n = %d\n", n);
        printf("Please enter n:");
        scanf("%d", &n);
    }
    printf("Program is over!\n");
}

int main()
{
    Solve();

    return 0;
}
