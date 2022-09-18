#include <stdio.h>
int main()
{
    int y, m, d, i;
    int sum = 0, leap;
    printf("Input year,month,day:");
    scanf("%d,%d,%d", &y, &m, &d);
    if (y < 1990 || m < 1 || m > 12 || d > 31 || d < 1)
    {
        printf("Input error!\n");
        return 0;
    }

    for (i = 1990; i < y; i++)
    {
        leap = ((i % 100 != 0 && i % 4 == 0) || (i % 400 == 0));
        sum = sum + ((leap != 0) ? 366 : 365);
    }

    //printf("%d ", sum);

    for (i = 1; i < m; i++)
    {
        switch (i)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            sum = sum + 31;
            break;
        case 2:
            leap = ((y % 100 != 0 && y % 4 == 0) || (y % 400 == 0));
            sum = sum + ((leap != 0) ? 29 : 28);
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            sum = sum + 30;
            break;
        }
    }

    //printf("%d ", sum);

    sum += d;
    sum = sum % 5;

    //printf("%d ", sum);

    if (sum == 4 || sum == 0)
    {
        printf("He is having a rest\n");
    }
    else
    {
        printf("He is working\n");
    }
    return 0;
}
/*
2014,12,22 ->wor

2017,3,8 ->res

2017,3,7 ->wor
*/
