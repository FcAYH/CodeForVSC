#include <stdio.h>
#include <math.h>

#define esp 1e-6

int main()
{
    float a, b, c, x1, x2, disc;
    scanf("%f,%f,%f", &a, &b, &c);
    if (a == 0)
    {
        if (b != 0)
        {
            x1 = -c / b;
            printf("x1=%f\n", x1);
        }
        else
            printf("Wrong!\n");
    }
    else
    {
        disc = b * b - 4 * a * c;
        if (disc < 0)
        {
            printf("without resolution");
        }
        else if (disc < esp)
        {
            x1 = (-b) / 2 * a;
            printf("x1=x2=%f\n", x1);
        }
        else
        {
            x1 = (-b + sqrt(disc)) / 2 * a;
            x2 = (-b - sqrt(disc)) / 2 * a;
            printf("x1=%f; x2=%f\n", x1, x2);
        }
    }
    while (1)
        ;
    return 0;
}
//1,2,1
