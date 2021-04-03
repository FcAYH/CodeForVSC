#include <stdio.h>
#define N 5
int main()
{
    int x, i, j;
    int a[N];
    printf("Enter 5 integers: ");
    printf("\n");

    for (i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter x: ");
    scanf("%d", &x);
    for (j = 0; j < N; j++)
        if (a[j] == x)
        {
            printf("Index is %d\n", j);
        }
        else
        {
            printf("Not Found");
        }

    return 0;
}
