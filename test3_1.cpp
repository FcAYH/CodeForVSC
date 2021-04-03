#include <bits/stdc++.h>

using namespace std;

const int Maxn = 10;

int qlist[Maxn];
int loss, n, len, mn = 0;
void Perm(int *, int, int, int, int, int set[Maxn][Maxn], int nlist[Maxn]);

int main()
{
    int *list;
    int set[Maxn][Maxn];
    int nlist[Maxn];
    memset(qlist, 0, sizeof(qlist));

    cin >> len >> loss;

    n = 0;

    while (cin >> qlist[n] && qlist[n] != -1)
        n++;
    mn = n;
    list = new int[n];

    for (int i = 0; i < n; i++)
    {
        list[i] = i;
    }

    memset(set, 0, sizeof(set));
    memset(nlist, 0, sizeof(nlist));
    Perm(list, 0, 0, n - 1, 1, set, nlist);

    return 0;
}

void Perm(int *list, int level, int k, int m, int count, int set[Maxn][Maxn], int nlist[Maxn])
{
    int i;
    int nset[Maxn][Maxn];
    int mlist[Maxn];
    int klist[Maxn];

    if (m == 0)
    {
        for (int l = k; l <= m; l++)
            set[count - 1][list[l]] = 1;

        int flag = 0;
        for (int l = 0; l < count; l++)
        {
            int sum = 0;
            for (int h = 0; h < n; h++)
            {
                if (set[l][h] == 1)
                    sum += qlist[h] + loss;
            }

            if (sum > len + loss)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
            mn = mn > count ? count : mn;
        return;
    }
    else
    {
        for (i = k; i <= m; i++)
        {
            for (int l = 0; l < level; l++)
                klist[l] = nlist[l];

            klist[level] = list[i];

            int left = 0;
            for (int l = 0; l <= m; l++)
            {
                int s;
                for (s = 0; s <= level; s++)
                    if (list[l] == klist[s])
                        break;
                if (s > level)
                    mlist[left++] = list[l];
            }

            for (int l = 0; l < Maxn; l++)
                for (int h = 0; h < Maxn; h++)
                    nset[l][h] = set[l][h];

            for (int l = 0; l <= level; l++)
                nset[count - 1][klist[l]] = 1;

            left--;
            if (left < 0)
            {
                int flag = 0;
                for (int l = 0; l < count; l++)
                {
                    int sum = 0;
                    for (int h = 0; h < n; h++)
                    {
                        if (nset[l][h] == 1)
                            sum += qlist[h] + loss;
                    }
                    if (sum > len + loss)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                    mn = mn > count ? count : mn;
            }
            Perm(mlist, 0, 0, left, count + 1, nset, klist);
            Perm(list, level + 1, i + 1, m, count, set, klist);
        }
    }
    return;
}
