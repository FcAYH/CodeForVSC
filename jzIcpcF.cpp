#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;

int sg[MAXN];
int counter[MAXN];

void SpragueGrundy(int x)
{
    sg[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        memset(counter, 0, sizeof(counter));
        if (i - 1 >= 0)
            counter[sg[i - 1]] = 1;

        if (i - 2 >= 0)
            counter[sg[i - 2]] = 1;

        counter[0] = 1;
        for (int j = 0; j < MAXN; j++)
        {
            if (counter[j] == 0)
            {
                sg[i] = j;
                break;
            }
        }
    }
}
void Solve()
{
    char s[MAXN];
    scanf("%s", s);

    SpragueGrundy(MAXN);
    memset(counter, 0, sizeof(counter));

    int len = strlen(s);
    for (int i = 0; i < len; i++)
        counter[s[i] - 'A']++;

    int ans = 0;
    for (int i = 0; i < 26; i++)
        ans ^= sg[counter[i]];

    printf("%s", !ans ? "Bob" : "Alice");
}

int main()
{
    Solve();

    return 0;
}
