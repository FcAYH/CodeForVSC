#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e6;
const ll mod=998244353;

ll gcd(ll x,ll y) {return y==0 ? x : gcd(y,x%y);}

ll a,b,c,d,x,y;

ll ksm(ll n,ll m)
{
	ll ret=1;
	while(m)
	{
		if(m&1) ret=(ret*n)%mod;
		m>>=1;
		n=(n*n)%mod;
	}
	return ret%mod;
}

int main()
{
	cin>>a>>b>>c>>d>>x>>y;
	ll ans=1;
	for(int i=a;i<=b;i++)
	{	
		for(int j=c;j<=d;j++)
		{
			ans=(ans*gcd(ksm(x,i),ksm(y,j)))%mod;
		}
		//printf("%lld\n",ans);
	}
	printf("%lld\n",ans);
	system("pause");
	return 0;
}
//0 2 0 4 120 180