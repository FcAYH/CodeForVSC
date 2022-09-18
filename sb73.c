#include <stdio.h>

int zz = 0;

int MakeVal(int *a, int k)
{
    a[0] = k / 1000;
    a[1] = k / 100 % 10;
    a[2] = k / 10 % 10;
    a[3] = k % 10;
    return 1;
}

int FindVal(int a, int b, int c, int d)
{
    return (a * 1000 + b * 100 + c * 10 + d);
}

void Solve()
{
    printf("There are magic aquares with invertable primes as follow:\n");

    int a[9000];
    int i, j, k, l = 0, num = 0;
    int p[300][5];

    for (i = 1000; i <= 9999; i++)
    {
        int key = 1;
        for (j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                key = 0;
                break;
            }
        }
        if (key)
        {
            a[l++] = 1;
        }
        else
            a[l++] = 0;
    }

    for (i = 1000; i <= 9999; i++)
    {
        if (a[i - 1000])
        {
            j = 1;
            k = 0;
            while (j <= 1000)
            {
                k = k + (i % (j * 10) / j) * 1000 / j;
                j = j * 10;
            }
            if (i >= k && a[k - 1000])
            {
                a[i - 1000] = i;
                a[k - 1000] = k;
                p[num++][0] = i;
                MakeVal(&p[num - 1][1], i);
                p[num++][0] = k;
                MakeVal(&p[num - 1][1], k);
            }
        }
    }
    for (i = 1000; i <= 9999; i++)
        if (a[i - 1000] == 1)
            a[i - 1000] = 0;

    for (int t1 = 0; t1 < num; t1++)
    {
        for (int k1 = 0; k1 < num; k1++)
        {
            if (p[t1][1] != p[k1][1])
                continue;
            for (int k2 = 0; k2 < num; k2++)
            {
                if (p[t1][2] != p[k2][1])
                    continue;
                for (int k3 = 0; k3 < num; k3++)
                {
                    if (p[t1][3] != p[k3][1])
                        continue;
                    for (int k4 = 0; k4 < num; k4++)
                    {
                        if (p[t1][4] != p[k4][1])
                            continue;
                        int key = 1, r[4];

                        int zuoduijiao = FindVal(p[k1][1], p[k2][2], p[k3][3], p[k4][4]) - 1000;
                        int youduijiao = FindVal(p[k1][4], p[k2][3], p[k3][2], p[k4][1]) - 1000;
                        r[0] = FindVal(p[k1][1], p[k2][1], p[k3][1], p[k4][1]) - 1000;
                        r[1] = FindVal(p[k1][2], p[k2][2], p[k3][2], p[k4][2]) - 1000;
                        r[2] = FindVal(p[k1][3], p[k2][3], p[k3][3], p[k4][3]) - 1000;
                        r[3] = FindVal(p[k1][4], p[k2][4], p[k3][4], p[k4][4]) - 1000;

                        if (!a[zuoduijiao] || !a[youduijiao])
                        {
                            key = 0;
                            continue;
                        }
                        if ((!a[r[0]]))
                        {
                            key = 0;
                            continue;
                        }
                        if ((!a[r[1]]))
                        {
                            key = 0;
                            continue;
                        }
                        if ((!a[r[2]]))
                        {
                            key = 0;
                            continue;
                        }
                        if ((!a[r[3]]))
                        {
                            key = 0;
                            continue;
                        }
                        if (key)
                        {
                            printf("No.%d\n", ++zz);
                            printf("%6d%6d%6d%6d\n", p[k1][0] / 1000, (p[k1][0] % 1000) / 100, p[k1][0] % 100 / 10, p[k1][0] % 10);
                            printf("%6d%6d%6d%6d\n", p[k2][0] / 1000, (p[k2][0] % 1000) / 100, p[k2][0] % 100 / 10, p[k2][0] % 10);
                            printf("%6d%6d%6d%6d\n", p[k3][0] / 1000, (p[k3][0] % 1000) / 100, p[k3][0] % 100 / 10, p[k3][0] % 10);
                            printf("%6d%6d%6d%6d\n", p[k4][0] / 1000, (p[k4][0] % 1000) / 100, p[k4][0] % 100 / 10, p[k4][0] % 10);
                        }
                    }
                }
            }
        }
    }
    printf("\n");
}

int main()
{
    Solve();

    return 0;
}
