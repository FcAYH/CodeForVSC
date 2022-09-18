#include <stdio.h>

void Solve()
{
    printf("Please enter the number:\n");

    int a;
    scanf("%d", &a);
    if (a == -1)
        printf("over!\n");

    int odd = 0, even = 0;
    while (a != -1)
    {
        (a % 2) ? odd++ : even++;
        printf("%d:", a);

        (a % 2) ? printf("odd\n") : printf("even\n");
        scanf("%d", &a);
    }

    printf("The total number of odd is %d\n", odd);
    printf("The total number of even is %d", even);
}

int main()
{
    Solve();

    return 0;
}
