#include <stdio.h>

int MaxCommonFactor(int a, int b);

main()
{
    int a, b, x;
    printf("Input a,b:");
    scanf("%d,%d", &a, &b);
    x = MaxCommonFactor(a, b);
    if (x < 0)  printf("Input Error!\n");
    printf("%d\n", x);

    while(1);
    
}

int MaxCommonFactor(int a, int b)
{
    if (a <= 0 || b <= 0)	
        return -1;
    else if (a != b)
    {
        if (a > b)	
            return MaxCommonFactor(a - b,b);
        else if (b > a)
            return  MaxCommonFactor(b - a,a);
        else return a;
    }
}