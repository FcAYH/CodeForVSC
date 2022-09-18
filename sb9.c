#include <stdio.h>
void  Squeeze(char *a,char *s, char c);
int main()
{
    char a[80],c, s[80]={0};
    scanf("%s",a);
    getchar();
    scanf("%c",&c);
    Squeeze(a, s, c);
    printf("%s\n",s);
    while(1);
    return 0 ;
}
void  Squeeze(char *a,char *s, char c)
{
    int i,j=0;
    for (i=0; a[i]!='\0'; i++)
    {
        if (a[i] != c)
        {
            s[j] = a[i]; 
            j++;
        }
    }
}
//sdfsadfs a
