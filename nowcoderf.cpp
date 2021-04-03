#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int Maxn=300;
typedef long long ll;
const ll Mod=998244353ll;
int n;
ll L[Maxn],R[Maxn];
inline ll Quick_Pow(ll a,ll b)
{
    ll ret=1ll;
    while(b>0)
    {
        if(b&1) ret*=a,ret%=Mod; a=a*a,a%=Mod; b>>=1;
    }
    return ret;
}
inline ll Inv(ll x)
{
    return Quick_Pow(x,Mod-2);
}
inline ll Work(int x,int y)
{
    ll y1=L[x],y2=R[x];
    ll x1=L[y],x2=R[y];
    ll S=((y2-y1)*(x2-x1))%Mod;
    if(x1>y2) return 0ll;
    if(x2<y1) return 1ll;
    
    else if(x1>=y1) return (((y2-x1)*(y2-x1))%Mod*Inv(2ll*S))%Mod;
    else return (((2ll*S)-((x2-y1)*(x2-y1)))%Mod*Inv(2ll*S))%Mod;
}
void Solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld%lld",&L[i],&R[i]);
    ll ans=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++) ans*=Work(i,j),ans%=Mod;
    }
    cout<<ans<<endl;
}
int main()
{
    Solve();
    system("pause");
    return 0;
}