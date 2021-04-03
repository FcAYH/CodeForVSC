#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod=1000000007ll;
ll n,k;
void Solve()
{
    scanf("%lld%lld",&n,&k);
    ll ret=0ll;
    ll last=0ll;
    for(ll i=1;i<=min(n,k);i=last+1)
    {
        last=n/(n/i);
        ret+=(n/i)%Mod*(min(last-i+1ll,k-i+1ll)%Mod);
        ret%=Mod;
    } 
    //cout<<ret<<endl;
    last=0;
    ll in=n-1;
    for(ll i=1;i<=min(in,k);i=last+1)
    {
        last=in/(in/i);
        ret+=(in/i)%Mod*(min(last-i+1ll,k-i+1ll)%Mod);
        ret%=Mod;
    }
    //cout<<ret<<endl;
    //if(k>n) ret=ret+k-n;
    ret=ret-n+k; 
    while(ret<0) ret=(ret+Mod);
    ret%=Mod;
    printf("%lld\n",ret);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
//124123515 125125
//12431513235 1241531452