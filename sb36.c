#include <stdio.h>

int gcd(int x, int y)
{
    return (!y) ? x : gcd(y, x % y);
}
void Solve()
{
    int a, b;
    printf("Input a,b:");
    scanf("%d%d", &a, &b);
    if (a > 0 && b > 0)
    {
        printf("Greatest Common Divisor of %d and %d is %d", a, b, gcd(a, b));
    }
    else
    {
        printf("Input number should be positive!");
    }
}

int main()
{
    Solve();

    return 0;
}

/*
Input a,b:45,54
Greatest Common Divisor of 45 and 54 is 9
Input a,b:45,-34
Input number should be positive!
Input a,b:45,77
Greatest Common Divisor of 45 and 77 is 1
Input a,b:45,0
Input number should be positive!
*/
