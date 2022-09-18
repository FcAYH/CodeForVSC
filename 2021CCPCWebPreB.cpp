#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int Maxn = 101;
const int MaxLength = 1000100;

inline int read()
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

char *charList;
int *listCount;
char str[Maxn][13];

void Solve()
{
    int T = read();
    while (T--)
    {
        int vis[27];

        int n = read(), diff = 0;
        listCount = new int[n + 1];

        for (int i = 1; i <= n; i++)
        {
            scanf("%s", str[i]);
            listCount[i] = strlen(str[i]);
            for (int j = 0; j < listCount[i]; j++)
                if (!vis[str[i][j] - 'a'])
                    vis[str[i][j] - 'a'] = 1, diff++;
        }

        charList = new char[MaxLength];
        int rest = n, nowCount = 1, nowPos = 0;
        while (rest > 0)
        {
            charList[++nowPos] = str[nowCount][--listCount[nowCount]];
            if (listCount[nowCount] == 0)
            {
                rest--;
                listCount[nowCount] = strlen(str[nowCount]);
            }
        }
        charList[nowPos] = '\0';

        int length = strlen(charList);
        int counter = 0, left = 0, right = 0, ans = length;
        memset(vis, 0, sizeof(vis));

        while (right < length)
        {
            while (right < length && counter < diff)
            {
                if (!vis[charList[right] - 'a'])
                {
                    vis[charList[right] - 'a'] = 1;
                    counter++;
                }
                else
                    vis[charList[right] - 'a']++;
            }

            while (left <= right && counter == diff)
            {
                if (vis[charList[left] - 'a'] > 1)
                {
                    vis[charList[left] - 'a']--;
                    left++;
                }
            }

            ans = min(ans, right - left + 1);
        }

        printf("%d\n", ans);
    }
}

int main()
{
    Solve();

    return 0;
}
