#include <bits/stdc++.h>

using namespace std;

int f(int a, char *b)
{
    // 测试一下
    // 第二次测试
}

void Solve()
{
    int n;
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int main()
{
    // X 表达式必须是可以修改的左值
    // int *p(int, char);
    // p = &f;

    // X 如此定义p，不符合语法
    // int (*)p();
    // p = &f;

    // X 表达式必须是可以修改的左值
    // int *p();
    // p = f;

    // √
    int (*p)(int, char *);
    p = f;

    Solve();

    return 0;
}
