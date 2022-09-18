#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll Mod=1000000007;
ll n,a,b;
int t;
inline ll Quick_Pow(ll a,ll b)
{
    ll ret=1ll;
    while(b>0)
    {
        if(b&1) ret*=a; a=a*a; b>>=1; ret%=Mod; a%=Mod;
    }
    return ret%Mod;
}
void Solve()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&n,&a,&b);
        cout<<Quick_Pow(a,n)<<" "<<Quick_Pow(b,Mod-2)<<" "<<Quick_Pow(Quick_Pow(b,Mod-2),n)<<endl;
        cout<<Quick_Pow(a,n)*Quick_Pow(Quick_Pow(b,Mod-2),n)%Mod<<endl;
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}