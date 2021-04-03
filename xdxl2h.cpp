#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
const ll Mod=1000000007;
int t,n,m;
ll C[1020][1020];
inline ll Quick_Pow(ll a,ll b)
{
    ll ret=1ll;
    while(b>=1)
    {
        if(b&1) ret*=a; a*=a,b>>=1; a%=Mod,ret%=Mod;
    }
    return ret;
}
void C_Ini()
{
    C[0][0]=1;
    for(int i=1;i<=1000;i++) C[i][0]=1;
    for(int i=1;i<=1000;i++)
        for(int j=1;j<=1000;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
}
void Solve()
{
    C_Ini();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        ll ans=0;
        for(int i=m;i<=n;i++) ans+=C[n][i],ans%=Mod;
        ans=ans*Quick_Pow(Quick_Pow(2,n),Mod-2)%Mod;
        printf("%lld\n",ans);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}