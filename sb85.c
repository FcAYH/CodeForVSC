#include <stdio.h>

int Search(int a[], int n, int x)
{
    for (int i = 1; i <= 10; i++)
    {
        if (a[i] == x)
        {
            printf("Subscript of x is %d\n", i - 1);
            return 1;
        }
    }
    return 0;
}

void Solve()
{
    printf("Input 10 numbers:\n");
    int a[11];
    for (int i = 1; i <= 10; i++)
        scanf("%d", &a[i]);

    int x;
    printf("Input x:\n");
    scanf("%d", &x);

    int n = 0;
    if (!Search(a, n, x))
        printf("Not found!\n");
}

int main()
{
    Solve();

    return 0;
}
