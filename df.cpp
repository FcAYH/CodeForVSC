#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;
int mod1[32], mod2[32];
int main()
{
    while (1)
    {
        bool flag = 0;
        double dec, x, f;
        cin >> x;
        if (x < 0)
            x = -x, flag = 1;

        dec = floor(x);
        double fac = x - dec;

        int i = 1, d;
        d = dec;
        while (d != 0)
        {
            mod1[i] = d % 2;
            d /= 2;
            i++;
        }

        int k = 1;
        f = fac;

        while (f != 1)
        {
            int flag = 0;
            f *= 2;
            if (f <= 1)
                flag = 1;
            mod2[k] = f / 1.0;
            if (flag == 0)
            {
                double t = floor(f);
                double f1 = f - t;
                f = f1;
            }
            k++;
            if (k == 31)
                break;
        }

        if (flag)
            printf("-");
        if (i == 1)
            printf("0");
        for (int j = i - 1; j >= 1; j--)
        {
            printf("%d", mod1[j]);
        }
        printf(".");
        for (int j = 1; j <= k - 1; j++)
        {

            printf("%d", mod2[j]);
        }
        if (x == '#')
            break;
    }
    return 0;
}
