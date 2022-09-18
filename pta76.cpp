#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b;
int All[101011];
char s1[101011];
int Calc()
{
    int len=strlen(s1+1);
	ll temp=0;
	for(int i=1;i<=len;i++)
	{
		temp=temp*10+s1[i]-'0';	
		All[len-i+1]=temp/b;
		temp%=b;
	}
    if(!temp) 
	{
        while(All[len]==0) len--;
	    for(int i=len;i>=1;i--)
	    {
	    	printf("%d",All[i]);
	    }
        return 1;
    }
    return 0;
}
void Solve()
{
    scanf("%lld",&b);
    if(b==1) printf("1 1");
    else if((11ll/b)&&!(11ll%b)) printf("%lld 2",11ll/b);
    else if((111ll/b)&&!(111ll%b)) printf("%lld 3",111ll/b);
    else
    {
        for(int i=4;i;i++)
        {
            for(int j=1;j<=i;j++) s1[j]='1';
            if(Calc()) 
            {
                printf(" %d",i); break ;
            }
        }
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}