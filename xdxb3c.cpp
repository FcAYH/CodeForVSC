#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Maxn=10100;
typedef long long ll;
ll n,h,ans;
ll f[Maxn],g[Maxn];
void Solve()
{
    scanf("%lld%lld",&n,&h);
	for(int i=1;i<=n;i++) scanf("%lld",&f[i]);
	for(int k=1;k<=n;k++)
	{
		ll H=0ll;
		for(int i=1;i<=k;i++) g[i]=f[i];
		sort(g+1,g+1+k);
		for(int i=k;i>=1;i-=2) H+=g[i];
		if(H<=h) ans=k;
	}
	printf("%lld",ans);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
