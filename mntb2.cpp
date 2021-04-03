#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll Mod=1e9+7;
const int Maxn=1001000;
char s[Maxn];
ll ans=0;
ll cnt=0;
inline ll Quick_Pow(ll a,ll b)
{
    ll ret=1ll;
    while(b>0ll)
    {
        if(b&1ll) ret*=a,ret%=Mod; a=a*a,a%=Mod; b>>=1ll;
    }
    return ret%Mod;
}
void Solve()
{
    cin>>(s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;i++)
    {
        if(s[i]=='0') cnt++;
        else ans+=Quick_Pow(2,cnt)-1,ans%=Mod;
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("password10.in","r",stdin);
    freopen("password10.out","w",stdout);
    Solve();
    //system("pause");
    return 0;
}