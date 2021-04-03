#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,f[1000],sum[1000];
char s[1000];
void Solve()
{
    scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		f[i]=s[i]-'0';
		sum[i]=sum[i-1]+f[i];
	}
	for(int i=1;i<n;i++)
	{
		int lim=sum[i],cnt=0,flag=1;
		for(int j=i+1;j<=n&&flag;j++)
		{
			cnt=cnt+f[j];
			if(cnt==lim&&sum[n]-sum[j]!=0) cnt=0;
			else if(cnt>lim) flag=0;
		}
		if(flag==0) continue;
		if(flag==1&&cnt<lim&&cnt!=0) flag=0;
		else if(flag==1&&cnt==lim)
		{
			printf("YES"); return ;
		}	
	}
	printf("NO");
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
