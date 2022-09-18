#include <stdio.h>

int A[3000];

void Solve()
{
    printf("共有多少个数？");
    int n;
    scanf("%d", &n);

    printf("后移多少个？");
    int a;
    scanf("%d", &a);

    printf("请以,号为间隔输入%d个数。\n", n);
    for (int i = 1; i <= n; i++)
    {
        if (i != n)
            scanf("%d,", &A[i]);
        else
            scanf("%d", &A[i]);
    }
    printf("移动后顺序为：\n");
    int cnt = 0;
    for (int i = n - a + 1; i <= n; i++)
    {

        cnt++;
        (cnt < n) ? printf("%d,", A[i]) : printf("%d\n", A[i]);
    }

    for (int i = 1; i <= n - a; i++)
    {
        cnt++;
        (cnt < n) ? printf("%d,", A[i]) : printf("%d\n", A[i]);
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

5
2
1,2,3,4,5
*/
