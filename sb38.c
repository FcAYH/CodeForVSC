#include <stdio.h>

void Solve()
{
    int age = 0;
    printf("Please input your age: ");
    scanf("%d", &age);

    printf("The heart beats in your life: %d", 75 * 60 * 24 * 365 * age);
}

int main()
{
    Solve();

    return 0;
}
