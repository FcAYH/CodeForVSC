#include<stdio.h>
#include<string.h>

char s[1000010];
int Cnt[30];

int main()
{
    gets(s);
    int len=strlen(s);

    for(int i=0;i<len;i++) if(s[i]>='a'&&s[i]<='z') Cnt[s[i]-'a']++;
    for(int i=0;i<=25;i++) if(Cnt[i]) printf("%c=%d\n",97+i,Cnt[i]);

    while(1);

    return 0;
}