#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
char s[205];
char stack1[205][110];
char stack2[205];
ll Cstack[205];
int len1=0,len2=0,len=0;
void Make_Suffix()
{
	for(int i=1;i<=len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
        {
            ++len1;
            int nowi=0;
            while(s[i]>='0'&&s[i]<='9') stack1[len1][++nowi]=s[i],i++;
            i--;
        }
		else
		{
			if(s[i]!=')')
			{
				if(stack2[len2]=='('||len2==0)
					stack2[++len2]=s[i];
				else 
				{
					if(s[i]=='+'||s[i]=='-')
					{
						while(stack2[len2]!='('&&len2>=1)
							stack1[++len1][1]=stack2[len2--];
						stack2[++len2]=s[i];
					}
					else if(s[i]=='*'||s[i]=='/')
					{
						while((stack2[len2]=='*'||stack2[len2]=='/')&&len2>=1)
							stack1[++len1][1]=stack2[len2--];
						stack2[++len2]=s[i];
					}
					else stack2[++len2]=s[i];
				}
			}
			else 
			{
				while(stack2[len2]!='('&&len2>=1)
				{
					stack1[++len1][1]=stack2[len2];
					len2--;
				}
				len2--;
			}
		}
		/*
		cout<<"*************"<<endl;
		cout<<stack1+1<<endl;
		cout<<stack2+1<<endl;
		cout<<"*************"<<endl;
		*/
	}
	while(len2)
	{
		stack1[++len1][1]=stack2[len2--];
	}
}
void Calc__Expression()
{
	len=0;
	for(int i=1;i<=len1;i++)
	{
		if(stack1[i][1]>='0'&&stack1[i][1]<='9')
		{	
            int ret=0,nowi=1;
            while(stack1[i][nowi]>='0'&&stack1[i][nowi]<='9') ret=ret*10+stack1[i][nowi]-'0',nowi++;
            Cstack[++len]=(ll)ret;
        }
        else 
		{		
			ll num1=Cstack[len--];
			ll num2=Cstack[len--];
			switch(stack1[i][1])
			{
				case '+':
				{
					Cstack[++len]=num2+num1;
					break ;
				}
				case '-':
				{
					Cstack[++len]=num2-num1;
					break ;
				}
				case '*':
				{
					Cstack[++len]=num2*num1;
					break ;
				}
				case '/':
				{
					Cstack[++len]=num2/num1;
					break ;
				}
			}
		}
	}
    printf("%lld\n",Cstack[1]);
}
int main()
{
	cin>>(s+1);
	len=strlen(s+1);
	Make_Suffix();
	Calc__Expression();
    //system("pause");
	return 0;
}
/*
8-(3+2*6)/5+4

9*9*9*9*9

12+(4-82)*7

12*24*9+6-8

888+223*2+(2220+4)
*/