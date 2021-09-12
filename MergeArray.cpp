#include <stdio.h>

int a[20], b[20];
int ans[20];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= m; i++)
        scanf("%d", &b[i]);

    int cnt = 1;
    int i = 1, j = 1;

    while (i <= n && j <= m)
    {
        if (a[i] < b[j])
        {
            ans[cnt] = a[i];
            cnt++;
            i++;
        }
        else
        {
            ans[cnt] = b[j];
            cnt++;
            j++;
        }
    }

    while (i <= n)
    {
        ans[cnt] = a[i];
        cnt++;
        i++;
    }

    while (j <= m)
    {
        ans[cnt] = b[j];
        cnt++;
        j++;
    }

    for (int i = 1; i <= n + m; i++)
        printf("%d ", ans[i]);

    return 0;
}

/*
5 6
2 11 42 52 626
3 4 65 77 544 777
*/
