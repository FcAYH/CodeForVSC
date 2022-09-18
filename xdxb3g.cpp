#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
long long ans,f[5005000];
void Solve()
{
    scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&f[i]);
    if(n==1)
	sort(f+1,f+1+n);
	if(f[1]>0&&f[n]>0)
	{
		for(int i=2;i<=n;i++) ans+=f[i];
		printf("%lld\n",ans-f[1]);
		return ;
	}
	else if(f[1]<0&&f[n]<0)
	{
		for(int i=1;i<n;i++) ans+=f[i];
		printf("%lld\n",-ans+f[n]);
		return ;
	}
	else
	{
		for(int i=1;i<=n;i++) ans+=(long long)abs(f[i]);
		printf("%lld\n",ans);
		return ;
	}
}
int main()
{
    Solve();
    system("pause");
    return 0;
}