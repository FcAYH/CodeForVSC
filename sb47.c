//亲密数
#include <stdio.h>

int main()
{
    int a, i, b, n;
    for (a = 1; a < 10000; a++)
    {

        for (b = 0, i = 1; i <= a / 2; i++)
        {
            if (!(a % i))
            {
                b += i;
            }
        }

        for (n = 0, i = 1; i <= b / 2; i++)
        {
            if (!(b % i))
            {
                n += i;
            }
        }

        if (n == a && a < b)
        {
            printf("(%4d,%4d)\n", a, b);
        }
    }
    return 0;
}
