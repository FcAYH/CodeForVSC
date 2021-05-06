#include <bits/stdc++.h>

using namespace std;

class A
{
};

void Solve()
{
    int *p = new int(0);
    printf("%d", *p);
    delete p;
}

int *tmp;

void function1(int n)
{
    for (int i = 1; i <= n; i++)
        scanf("%d", &tmp[i]);

    sort(tmp + 1, tmp + 1 + n);
    for (int i = 1; i <= n; i++)
        printf("%d", tmp[i]);
}

void function2()
{
    int n;
    scanf("%d", &n);

    tmp = new int[n + 1];

    function1(n);
}

int main()
{
    function2();
    //Solve();

    return 0;
}
