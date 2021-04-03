#include<bits/stdc++.h>
#define debug(x) cout<<#x<<" = "<<x<<endl
#define int long long
using namespace std;

typedef long long ll;
const int maxn=1e6;
const ll mod=998244353;

ll a,b,c,d,x,y;
ll num1,num2,Num;
ll tot[maxn],tot1[maxn],tot2[maxn],gong[maxn],z1[maxn],z2[maxn];

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

signed main()
{
	scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&x,&y);
	if(!a) a=1;
	if(!c) c=1;
	ll tmp1=sqrt(x),pre1=x;
	for(int i=2;i<=3000000;i++)
	{
		if(pre1%i==0) tot1[++num1]=i;
		while(pre1%i==0)
		{
			pre1/=i;
			z1[i]++;
		}
		if(!pre1) break;
	}
	ll tmp2=sqrt(y),pre2=y;
	for(int i=2;i<=3000000;i++)
	{
		if(pre2%i==0) tot2[++num2]=i;
		while(pre2%i==0)
		{
			pre2/=i;
			z2[i]++;
		}
		if(!pre2) break;
	}
	for(int i=1;i<=num1;i++)
		for(int j=1;j<=num2;j++)
			if(tot1[i]==tot2[j])
				gong[++Num]=tot1[i];
	for(int i=a;i<=b;i++)
	{
		for(int j=1;j<=Num;j++)
		{
			ll tmp=z1[gong[j]]*i;
			if(tmp>=z2[gong[j]]*d) tot[j]+=(z2[gong[j]]*c+z2[gong[j]]*d)*(d-c+1)/2;
			else if(tmp<=z2[gong[j]]*c) 
			{
				tot[j]+=z1[gong[j]]*i*(d-c+1);
			}
			else
			{
				ll cnt=(z1[gong[j]]*i-z2[gong[j]]*c)/z2[gong[j]];
				ll cnt2=((z2[gong[j]]*d-z1[gong[j]]*i)-1)/z2[gong[j]]+1;
				tot[j]+=((z2[gong[j]]*c+z2[gong[j]]*(c+cnt))*(cnt+1)/2);
				if(!cnt2) tot[j]+=z1[gong[j]]*i;
				else tot[j]+=z1[gong[j]]*i*cnt2;
			}
		}
	}
	ll ans=1;
	for(int i=1;i<=Num;i++)
	{
		ans*=ksm(gong[i],tot[i]);
		ans%=mod;
	}
	printf("%lld\n",ans%mod); 
	//system("pause");
	return 0;
}

/*
8703 16829 2317 15259 13720 1610
0 2 0 3 12 20 65536
*/