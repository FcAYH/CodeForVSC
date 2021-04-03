#include <stdio.h>

int Search(int a[], int n, int x)
{
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == x)
            return i - 1;
    }
    return -1;
}

void Solve()
{
    printf("Input 10 numbers:\n");

    int a[12];
    for (int i = 1; i <= 10; i++)
        scanf("%d", &a[i]);

    /*
    -1
    -2
    -3
    -4
    0
    1
    2
    3
    4
    5
    
    5
    */
    int x;
    printf("Input x:\n");
    scanf("%d", &x);

    int pos = Search(a, 10, x);
    (pos != -1) ? printf("Subscript of x is %d\n", pos) : printf("Not found!\n");
}

int main()
{
    Solve();

    return 0;
}
