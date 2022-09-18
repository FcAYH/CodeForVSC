#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5 + 10;

struct EDGE
{
    int next, to;
} E[Maxn << 1];

char str[Maxn];
int num = 0, cnt = 0, Ansc = 0;
int head[Maxn];

struct ANS
{
    int first, second;
} Ans[Maxn];

inline void add_edge(int x, int y)
{
    E[++num].next = head[x], E[num].to = y, head[x] = num;
}

inline void link(int x, int y)
{
    add_edge(x, y), add_edge(y, x);
}

bool check(int len)
{
    if (str[1] == '0')
        return false;
    if (str[len] == '1')
        return false;
    for (int i = 2; i < len; i++)
    {
        if (str[i] == '1' && str[len - i] != '1')
            return false;
        if (str[i] == '0' && str[len - i] != '0')
            return false;
    }
    return true;
}

inline void dfs(int cur, int len)
{
    int ilen = len - 1;
    for (int i = ilen; i >= 1; i--)
    {
        if (str[i] == '1')
        {
            while (ilen >= i)
            {
                ilen -= i;
                link(cur, ++cnt);
                dfs(cnt, i);
            }
            break;
        }
    }
    while (ilen)
    {
        ilen -= 1;
        link(cur, ++cnt);
        dfs(cnt, 1);
    }
}

inline void print(int x, int y)
{
    for (int i = head[x]; i; i = E[i].next)
    {
        if (E[i].to == y)
            continue;
        Ans[++Ansc].first = x, Ans[Ansc].second = E[i].to;
        //printf("%d %d\n", x, E[i].to);
        print(E[i].to, x);
    }
}

inline int cmp(ANS a, ANS b)
{
    return (a.first == b.first) ? a.second < b.second : a.first < b.first;
}

void Solve()
{
    scanf("%s", str + 1);
    int len = strlen(str + 1);
    if (!check(len))
    {
        puts("-1");
        return;
    }
    cnt = 1;
    dfs(cnt, len);
    print(1, 0);

    sort(Ans + 1, Ans + 1 + Ansc, cmp);
    for (int i = 1; i <= Ansc; i++)
        printf("%d %d\n", Ans[i].first, Ans[i].second);
}

int main()
{
    Solve();
    return 0;
}
