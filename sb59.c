#include <stdio.h>

void Solve()
{
    printf("Enter three integer: ");
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    int sum = 0, rem = 0;
    float ave = 0;

    sum = a + b + c;
    ave = (float)sum / 3.0;
    rem = sum % 3;

    printf("SUM = %4d\nAVERAGE = %.2f  REMAINDER = %3d\n", sum, ave, rem);
}

int main()
{
    Solve();

    return 0;
}
