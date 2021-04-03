#include <math.h>
#include <stdio.h>

void fun(char *s, char *t, int *k)
{
    int i;
    *k = 0;
    for (i = 0; s[i]; i++)
        if ('0' <= s[i] && s[i] <= '9')
        {
            t[*k] = s[i];
            *k += 1;
        }
}
int main()
{
    char str[100], tOrigin[9];
    double n;
    int i, k;
    printf("Please enter string s:");
    scanf("%s", str);
    fun(str, tOrigin, &k);
    for (i = 0; i < k; i++)
        n += (double)(tOrigin [k - i - 1] - '0') * pow(10, i);
    printf("The result is: %.0lf", n);

    while(1);
    return 0;
}