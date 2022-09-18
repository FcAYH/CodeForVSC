#include <bits/stdc++.h>

using namespace std;

void Solve()
{
    freopen("asmIn.txt", "r", stdin);
    freopen("toUp.txt", "w", stdout);
    char ch = '\0';
    while (scanf("%c", &ch) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            putchar('A' + (ch - 'a'));
        }
        else
        {
            putchar(ch);
        }
    }
}

int main()
{
    Solve();

    return 0;
}
