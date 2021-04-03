#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
const int Maxn=3000100;
const ll Mod=998244353;
int n;
ll Pre[Maxn];
inline ll Quick_Pow(ll a,ll b)
{
    ll ret=1ll;
    while(b)
    {
        if(b&1) ret*=a; a*=a,b>>=1; ret%=Mod,a%=Mod;
    }
    return ret;
}
inline ll Inv(ll x)
{
    return Quick_Pow(x,Mod-2);
}
void Ini_()
{
    Pre[1]=1;
    for(int i=2;i<=3000000;i++) Pre[i]=i*Pre[i-1],Pre[i]%=Mod;
}
void Solve()
{
    Ini_();
    while(scanf("%lld",&n)!=EOF)
    {
        ll ans=((Pre[2*n+1]*Inv(Pre[n]))%Mod*Inv(Pre[n]))%Mod;
        printf("%lld\n",Inv(ans)%Mod);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}