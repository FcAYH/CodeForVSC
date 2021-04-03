#include<stdio.h>
#include<string.h>

char s[1000010];

int main()
{
    scanf("%s",s);
    int len=strlen(s);
    len--;
    for(int i=0;i<len;i++)
    {
        if(s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/'&&(s[i]<'0'||s[i]>'9'))
        {
            printf("错误的运算符：%c",s[i]); while(1);return 0;
        }
    }
    int Nowp=0;
    int sum=0;
    while(s[Nowp]>='0'&&s[Nowp]<='9')
    {
        sum=sum*10+s[Nowp]-'0'; Nowp++;
    }
    for(int i=0;i<len;i++)
    {
        int flag=i+1;
        int Next_N=0;
        switch (s[i])
        {
            case '+':
                while(s[flag]>='0'&&s[flag]<='9')
                {
                    Next_N=Next_N*10+s[flag]-'0'; flag++;
                }
                sum=sum+Next_N;
                break ;
            case '-':
                while(s[flag]>='0'&&s[flag]<='9')
                {
                    Next_N=Next_N*10+s[flag]-'0'; flag++;
                }
                sum=sum-Next_N;
                break ;
            case '*':
                while(s[flag]>='0'&&s[flag]<='9')
                {
                    Next_N=Next_N*10+s[flag]-'0'; flag++;
                }
                sum=sum*Next_N;
                break ;
            case '/':
                while(s[flag]>='0'&&s[flag]<='9')
                {
                    Next_N=Next_N*10+s[flag]-'0'; flag++;
                }
                sum=sum/Next_N;
                break ;
        }
        i=flag-1;
    }
    printf("%d",sum);


    while(1);
    return 0;
}