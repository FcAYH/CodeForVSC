#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,p,k;
ll T;
inline ll read()
{
	ll rt=0ll,in=1ll; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') in=-1ll;ch=getchar();}
	while(ch>='0'&&ch<='9'){rt=rt*10ll+ch-'0';ch=getchar();}
	return rt*in;
}

ll G,p1,q1;
inline ll Exgcd(ll x,ll y)
{
	if(y==0){p1=1,q1=0; return x;}
	ll Gcd=Exgcd(y,x%y);
	ll t;
	t=p1; p1=q1; q1=t-(x/y)*q1;
	return Gcd;
}

inline ll Quick_Pow(ll a,ll b,ll Mod)
{
    ll ret=1ll;
    while(b>0ll)
    {
        if(b&1ll) ret*=a,ret%=Mod; a=a*a,a%=Mod; b>>=1ll;
    }
    return ret%Mod;
}

ll workk(ll nowwa)
{
	ll qwq=0,poi=1;
	if(nowwa==1) return n+1;
	if(nowwa==0) return 1;
	if(! (nowwa&1)) {qwq=Quick_Pow(n,nowwa,p);nowwa--;}
	poi+=Quick_Pow(n,(nowwa+1)>>1,p);poi%=p;
//	outt(nowwa);outt(poi);outt(qwq);hh;
	return (workk(nowwa>>1)*poi+qwq)%p;
}

void Solve()
{
    T=read();
    while(T--)
    {
        n=read(),k=read(),p=read();
        k--; printf("%lld\n",workk(k));
    }
}
int main()
{
    Solve();
    //system("pause");
    return 0;
}
/*
2
3 5 1000 
4 7 50
*/