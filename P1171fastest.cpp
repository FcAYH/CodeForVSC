#include <bits/stdc++.h>
using namespace std;

struct node
{
    int dis, num;
} a[25][25];

int n, flag;
int book[25];

int ans = INT_MAX;

void dfs(int f, int len, int num, int zhi)
{
    if (len + zhi >= ans || (f == 1 && num != n + 1 && !flag))
        return;
    if (flag == 0 && f == 1 && num == n + 1)
    {
        ans = min(ans, len);
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        if ((!book[a[f][i].dis] && a[f][i].dis != f) || (a[f][i].dis == 1 && num == n))
        {
            flag = 0;
            book[a[f][i].dis] = 1;
            dfs(a[f][i].dis, len + a[f][i].num, num + 1, zhi - a[f][2].num);
            book[a[f][i].dis] = 0;
        }
    }
}

bool cmp(node x, node y)
{
    return x.num < y.num;
}

int sum;

int main()
{
    cin >> n;
    flag = 1;
    sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cin >> a[i][j].num;
            a[j][i].num = a[i][j].num;
            a[i][j].dis = j;
            a[j][i].dis = i;
        }
        sort(a[i] + 1, a[i] + n + 1, cmp);
        sum += a[i][2].num;
    }
    dfs(1, 0, 1, sum);
    cout << ans;
    return 0;
}
