#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Maxn=22020;
ll f[Maxn];
ll p=1000000007;
int n,t;
void Solve()
{
    f[1]=1,f[2]=2;
	for(int i=3;i<=2000;i++) f[i]=(f[i-1]+f[i-2])%p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ll ans=f[n];
		for(int i=1;i<=n;i++) ans=(ans+f[i]*f[n-i+1])%p;
		printf("%lld\n",ans);
	}
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
