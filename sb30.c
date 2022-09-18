#include <stdio.h>

int n, m;

void fuc()
{
    printf("请输入m,n的值( m>n )：\n");
    scanf("%d %d", &m, &n);

    double Mm = 1.0;
    double Nn = 1.0;
    double MN = 1.0;

    for (int i = 1; i <= m; i++)
        Mm *= (double)i;
    for (int i = 1; i <= n; i++)
        Nn *= (double)i;
    for (int i = 1; i <= m - n; i++)
        MN *= (double)i;

    printf("n项之和为：%lf\n", Mm / (Nn * MN));
}

// P= m!/(n!*(m-n)!)

int main()
{
    fuc();

    while (1)
        ;

    return 0;
}
