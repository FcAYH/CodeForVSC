#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    char s[1000];

    for(int i=1;i<=4;i++)
    {
        printf("Input days:\n");
        scanf("%s",s);
        if(s[0]>'0'&&s[0]<='9')
        {
            int n=0,len=strlen(s);
            for(int i=0;i<len;i++) n=n*10+s[i]-'0';
            int sum=1;
            for(int i=2;i<=n;i++) sum=(sum+1)<<1;
            printf("x=%d\n",sum);
        }
    }

    while(1);

    return 0;
}