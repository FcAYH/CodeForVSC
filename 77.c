#include <stdio.h>

int Search(int a[], int n, int x)
{
    for (int i = 0; i < 10; i++)
        if (a[i] == x)
            return i;
    return 11;
}

void Solve()
{
    printf("Input 10 numbers:\n");
    int a[11];
    for (int i = 0; i < 10; i++)
        scanf("%d", &a[i]);

    printf("Input x:\n");
    int x;
    scanf("%d", &x);

    int pos = Search(a, 10, x);
    (pos == 11) ? printf("Not found!\n") : printf("Subscript of x is %d\n", pos);
}

int main()
{
    Solve();

    return 0;
}
