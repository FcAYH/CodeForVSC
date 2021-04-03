#include<bits\stdc++.h>
using namespace std;
typedef long long ll;

inline int read()
{
	int fl=1,rt=0; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
	return fl*rt;
}
inline ll read_ll()
{
	ll fl=1ll,rt=0ll; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') fl=-1ll; ch=getchar();}
	while(ch>='0'&&ch<='9'){rt=rt*10ll+ch-'0'; ch=getchar();}
	return fl*rt;
}
inline ll V2IDX(ll v,ll N,ll Ndr,ll nv){return v>=Ndr?(N/v-1):(nv-v);}

ll PrimeSum(ll N) 
{
    ll *S,*V,r=(ll)sqrt(N);
	ll Ndr=N/r;
	assert(r*r<=N&&(r+1)*(r+1)>N);
	ll nv=r+Ndr-1;
	V=new ll[nv],S=new ll[nv];
    for (ll i=0;i<r;i++) V[i]=N/(i+1);
    for (ll i=r;i<nv;i++) V[i]=V[i-1]-1;
    for (ll i=0; i<nv; i++) S[i]=V[i]*(V[i]+1)/2-1;
    for (ll p=2; p<=r; p++) 
	{
        if (S[nv-p] > S[nv-p+1]) 
		{
            ll sp = S[nv-p+1];
            ll p2 = p*p;
            for(ll i=0;i<nv;i++) 
			{
                if(V[i]>=p2) S[i]-=p*(S[V2IDX(V[i]/p,N,Ndr,nv)]-sp);
				else break;
            }
        }
    }
    return S[0];
}

void Solve()
{
	int t=0;
	t=read();
	ll n,K;
	while(t--)
	{
		n=read_ll(),K=read_ll();
		ll ans1=0ll;
		if(n%2) 
		{
			ll n1=(n+1ll)/2ll;
			ans1=((n+2ll)%K)*(n1%K)%K;
		}
		else
		{
			ll n1=(n+2ll)/2ll;
			ans1=((n+1ll)%K)*(n1%K)%K;
		}
		printf("%lld\n",(ans1-3ll+(PrimeSum(n+1)-2ll)%K)%K);
	}
}
int main() 
{
	Solve();
	system("pause");
	return 0;
}