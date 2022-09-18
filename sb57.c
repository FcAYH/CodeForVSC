#include <stdio.h>

void Solve()
{
    int a[101];

    printf("共有多少个数？");
    int n;
    scanf("%d", &n);

    printf("后移多少个？");
    int x;
    scanf("%d", &x);

    printf("请以,号为间隔输入%d个数。\n", n);
    for (int i = 1; i <= n - 1; i++)
        scanf("%d,", &a[i]);
    scanf("%d", &a[n]);

    printf("移动后顺序为：\n");

    x %= 5;

    int cnt = 0;
    for (int i = n - x + 1; i <= n; i++)
    {
        cnt++;
        if (cnt != n)
            printf("%d,", a[i]);
        else
            printf("%d", a[i]);
    }
    for (int i = 1; i <= n - x; i++)
    {
        cnt++;
        if (cnt != n)
            printf("%d,", a[i]);
        else
            printf("%d", a[i]);
    }
}

int main()
{
    Solve();

    return 0;
}
/*
共有多少个数？5
后移多少个？2
请以,号为间隔输入5个数。
1,2,3,4,5
移动后顺序为：
4,5,1,2,3

*/
