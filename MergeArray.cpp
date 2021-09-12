#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    int *a = (int *)malloc(sizeof(int) * n);
    int *b = (int *)malloc(sizeof(int) * m);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    int *c = (int *)malloc(sizeof(int) * (m + n));

    int cnt = 0;
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            c[cnt] = a[i];
            cnt++;
            i++;
        }
        else
        {
            c[cnt] = b[j];
            cnt++;
            j++;
        }
    }

    while (i < n)
    {
        c[cnt] = a[i];
        cnt++;
        i++;
    }

    while (j < m)
    {
        c[cnt] = b[j];
        cnt++;
        j++;
    }

    for (int i = 0; i < n + m; i++)
        printf("%d ", c[i]);

    return 0;
}

/*
5 6
2 11 42 52 626
3 4 65 77 544 777
*/
