#include <stdio.h>
#define ARR_SIZE 80
void MyStrcat(char dstStr[], char srcStr[]);
int main()
{
    char s[ARR_SIZE], t[ARR_SIZE];
    printf("Please enter source string:\n");
    gets(s);
    printf("Please enter destination string:\n");
    gets(t);

    MyStrcat(s, t);
    printf("The concatenate string is:\n");
    puts(t);
    return 0;
}
void MyStrcat(char dstStr[], char srcStr[])
{
    int i = 0, j = 0;

    while (srcStr[i] != '\0')
    {
        i++;
    }

    for (; dstStr[j] != '\0'; i++, j++)
    {

        srcStr[i] = dstStr[j];
    }
    srcStr[i] = '\0';
}
