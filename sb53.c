#include <stdio.h>

int Gcd(int a, int b)
{
    return (!b) ? a : Gcd(b, a % b);
}
void Solve()
{
    int a, b;
    printf("Input a,b:");
    scanf("%d,%d", &a, &b);
    if (a <= 0 || b <= 0)
        printf("Input number should be positive!");
    else
        printf("Greatest Common Divisor of %d and %d is %d", a, b, Gcd(a, b));
}

int main()
{
    Solve();

    return 0;
}
/*

INPUT
45,54       

Input a,b:Greatest Common Divisor of 45 and 54 is 9
*/
