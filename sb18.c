#include <stdio.h>

int main()
{
    int n;

    printf("Input an integer number:");
    scanf("%d", &n);

    if (!(n % 2))
        printf("a is an even number\n");
    else
        printf("a is an odd number\n");

    while (1)
        ;
    return 0;
}