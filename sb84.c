#include <stdio.h>
#include <stdlib.h>
void Solve()
{
    char *ch;
    printf("Enter string:");

    ch = (char *)malloc(sizeof(char) * 101);
    scanf("%s", ch);
    int len = 0;
    for (ch; *ch != '\0'; ch++)
        len++;
    printf("string length=%d\n", len);
}

int main()
{
    Solve();

    return 0;
}
