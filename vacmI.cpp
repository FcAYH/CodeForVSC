#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
ll n,m,k,x;
ll ans=1;
ll Quick_Power(ll b,ll p)
{
	ll a=10;
	while(b>0)
	{
		if(b%2==1) ans=(ans*a)%p; b/=2; a=(a*a)%p;
	}
	return ans;
}
int main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
	m=m%n;
	ll qt=Quick_Power(k,n);
	printf("%lld",(qt%n*m%n+x)%n);
} 
//((10^k)*m+x)%n;
//?=10^k%n*m%n+x%n;