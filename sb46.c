#include <stdio.h>

void Solve()
{
    int x, y;
    printf("Enter integer X and Y:");
    scanf("%d%d", &x, &y);
    (x > y) ? printf("X>Y") : (x == y) ? printf("X=Y") : printf("X<Y");
}

int main()
{
    Solve();

    return 0;
}
