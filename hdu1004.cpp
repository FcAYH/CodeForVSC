#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod= 998244353ll;
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
inline ll Quick_Pow(ll a,ll b)
{
    ll ret=1;
    while(b>0)
    {
        if(b&1) ret*=a; a*=a,b>>=1; ret%=Mod,a%=Mod;
    }
    return ret;
}
void Solve()
{
    int t,n;
    ll jc=1ll;
    for(int i=1;i<=26;i++) jc*=i,jc%=Mod;
    t=read();
    while(t--)
    {
        n=read();
        if(n<=26) printf("%lld\n",Quick_Pow(26ll,(ll)n));
        else printf("%lld\n",jc*Quick_Pow(24ll,(ll)(n-26))%Mod);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}