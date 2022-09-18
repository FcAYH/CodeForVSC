#include <stdio.h>
#include <string.h>
void Solve()
{
    printf("Enter a string: ");
    char s[12];
    scanf("%s", s);

    int len = strlen(s);
    int num = 0;
    for (int i = 0; i <= len - 1; i++)
    {
        num = num * 10 + (s[i] - '0');
    }

    printf("digit = %d\n", num);
}

int main()
{
    Solve();

    return 0;
}
