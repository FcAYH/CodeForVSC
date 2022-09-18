#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Maxn=100100;
ll n,m,k,area;
ll f[Maxn];
void Solve()
{
    scanf("%lld%lld%lld",&n,&m,&k);
	if(2*n*m%k!=0)
	{
		printf("NO\n"); return ;
	}
	area=2*n*m/k;
	ll p=area;
	for(ll i=2;i*i<=p;i++) while(p%i==0) f[++f[0]]=i,p/=i;
	if(p) f[++f[0]]=p;
	ll Max=max(n,m);
	p=1;
	for(int i=1;i<=f[0];i++)
	{
		p*=f[i];
		if(p>Max)
		{
			p/=f[i]; break;
		}
	}
	if(p<=n&&area/p<=m)	printf("YES\n0 0\n%lld 0\n0 %lld",p,area/p);
	else if(p<=m&&area/p<=n) printf("YES\n0 0\n0 %lld\n%lld 0",p,area/p);
	else printf("YES\n0 0\n0 %lld\n%lld 0",m,area/m);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
