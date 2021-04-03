#include <stdio.h>

void Solve()
{
    char ch = getchar();
    while (ch != 'a')
    {
        putchar(ch);
        ch = getchar();
    }
}

int main()
{
    Solve();

    return 0;
}
