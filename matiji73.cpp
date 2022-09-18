#include <bits/stdc++.h>

using namespace std;

const int MaxN = 500005;
const int MaxV = 2000000;

char s[MaxN];
bool vis[MaxV];

int BinaryStringToInt(int l, int r)
{
    int factor = 1, val = 0;
    for (int i = r; i >= l; i--)
    {
        val += (s[i] == '1') ? factor : 0;
        factor <<= 1;
    }
    return val;
}

void Solve()
{
    scanf("%s", s);
    int k;
    scanf("%d", &k);
    int length = strlen(s);

    vis[BinaryStringToInt(0, k - 1)] = true;
    for (int i = k; i < length; i++)
    {
        vis[BinaryStringToInt(i - k + 1, i)] = true;
    }

    bool ok = true;
    for (int i = 0; i < pow(2, k); i++)
    {
        if (!vis[i])
        {
            ok = false;
            break;
        }
    }

    printf("%s", ok ? "true" : "false");
}

int main()
{
    Solve();

    return 0;
}
