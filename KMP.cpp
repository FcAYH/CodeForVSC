#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char s1[1000101];
char s2[1100];
int f[1100];
int len1, len2;

void Import()
{
    scanf("%s%s", s1 + 1, s2 + 1);
    len1 = strlen(s1 + 1);
    len2 = strlen(s2 + 1);
}
void Find_f_array()
{
    int k = 0;
    for (int i = 2; i <= len2; i++)
    {
        while (k > 0 && s2[k + 1] != s2[i])
            k = f[k];
        if (s2[k + 1] == s2[i])
            k++;
        f[i] = k;
    }
}
void KMP()
{
    int k = 0;
    for (int i = 1; i <= len1; i++)
    {
        while (k > 0 && s2[k + 1] != s1[i])
            k = f[k];
        if (s2[k + 1] == s1[i])
            k++;
        if (k == len2)
        {
            printf("%d\n", i - len2 + 1);
        }
    }
}

int main()
{
    Import();
    Find_f_array();
    KMP();

    return 0;
}
