#include <stdio.h>
#include <math.h>

void Solve()
{
    printf("Please enter the coefficients a,b,c:");
    float a, b, c;
    scanf("%f,%f,%f", &a, &b, &c);

    if (a == 0)
    {
        printf("It is not a quadratic equation!\n");
        return;
    }
    float d = (b * b) - 4 * a * c;
    float p = (-b) / (2.0 * a);
    float q = sqrt(abs(d)) / (2.0 * a);

    //printf("%f,%f\n", p, q);

    if (d == 0)
    {
        printf("x1 = x2 = %.2f\n", p);
    }
    else if (d > 0)
    {
        printf("x1 = %.2f, x2 = %.2f\n", p + q, p - q);
    }
    else
    {
        printf("x1 = %.2f+%.2fi, x2 = %.2f-%.2fi\n", p, q, p, q);
    }
}

int main()
{
    Solve();

    return 0;
}
/*
相等实根: "x1 = x2 = %.2f\n"
不相等的实根: "x1 = %.2f, x2 = %.2f\n"
一对共轭复根: "x1 = %.2f+%.2fi, x2 = %.2f-%.2fi\n"

2,3,2

Please enter the coefficients a,b,c:x1 = -0.75+0.66i, x2 = -0.75-0.66i
*/
