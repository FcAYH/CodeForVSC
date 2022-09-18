#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int Maxn=100002;
int t;
ll f[Maxn];
ll a,b,n;
ll len=1;
ll Quick_Pow(ll x, ll y)
{
    ll ans=1;
    x%=len;
    while(y)
    {
        if(y&1ll) ans=(ans*x)%len;
        x=x*x%len;y>>=1ll;
    }
    return ans%len;
}

void Solve()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&a,&b,&n);
        f[0]=0,f[1]=1;
        for(int i=2;i<=10000000;i++)
        {
            f[i]=(f[i-1]+f[i-2])%n;
            if(f[i]==f[1]&&f[i-1]==f[0])
            {
                len=i-2; break;
            }
        }
        ll k=Quick_Pow(a,b);
        cout<<f[k]<<endl;

    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}