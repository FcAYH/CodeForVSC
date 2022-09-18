#include <bits/stdc++.h>

using namespace std;
const int Maxn = 300000;
const int MaxBlock = 430;

int pen[Maxn];
int sum[MaxBlock][Maxn];
int mode[MaxBlock][MaxBlock];
int temp[Maxn];

int read()
{
    int fl = 1, rt = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            fl = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        rt = rt * 10 + ch - '0';
        ch = getchar();
    }
    return fl * rt;
}

int main()
{
    int n, q;
    n = read(), q = read();
    // scanf("%d%d", &n, &q);

    for (int i = 0; i < n; i++)
        pen[i] = read();

    int block = min(429.0, sqrt(n) + 1);
    int len = (n + block - 1) / block;

    for (register int i = 1; i <= block; i++)
    {
        for (register int j = 0; j < n; j++)
            sum[i][j] = sum[i - 1][j];
        for (register int j = (i - 1) * len; j < n && j < i * len; j++)
            sum[i][pen[j]]++;
    }

    for (register int i = 1; i <= block; i++)
    {
        for (register int j = i; j <= block; j++)
        {
            mode[i][j] = mode[i][j - 1];

            for (register int k = (j - 1) * len; k < n && k < j * len; k++)
            {
                int x = sum[j][pen[k]] - sum[i - 1][pen[k]];
                if (x > mode[i][j] || x == mode[i][j])
                    mode[i][j] = x;
            }
        }
    }
    int left, right, Ans;

    while (q--)
    {
        scanf("%d%d", &left, &right);
        left--, right--;

        int x = left / len + 1, y = right / len + 1;
        Ans = mode[x + 1][y - 1];

        for (register int i = left; i <= right && i < x * len; i++)
            temp[pen[i]] = max(0, sum[y - 1][pen[i]] - sum[x][pen[i]]);

        for (register int i = max(left, (y - 1) * len); i <= right; i++)
            temp[pen[i]] = max(0, sum[y - 1][pen[i]] - sum[x][pen[i]]);

        for (register int i = left; i < x * len && i <= right; i++)
        {
            temp[pen[i]]++;
            if (temp[pen[i]] > Ans || temp[pen[i]] == Ans)
                Ans = temp[pen[i]];
        }

        if (x != y)
        {
            for (register int i = (y - 1) * len; i <= right; i++)
            {
                temp[pen[i]]++;
                if (temp[pen[i]] > Ans || temp[pen[i]] == Ans)
                    Ans = temp[pen[i]];
            }
        }

        printf("%d\n", Ans);
    }

    return 0;
}
/*
10 4
3 3 4 2 6 7 3 9 0 3
1 4
2 9
4 10
6 8
*/
