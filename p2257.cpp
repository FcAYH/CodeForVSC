#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MaxN=10000000;
const int Maxn=10000011;
int cnt=0,T;
ll n,m;
int prime[Maxn];
int mobius[Maxn];
bool Not_p[Maxn];
ll sum[Maxn];
ll Pre[Maxn];
inline ll read()
{
    ll fl=1ll,rt=0ll; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1ll; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10ll+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Prime_Ini()
{
    Not_p[1]=1,mobius[1]=1;
    for(int i=2;i<=MaxN;i++)
    {
        if(!Not_p[i]) prime[++cnt]=i,mobius[i]=-1;
        for(int j=1;j<=cnt;j++)
        {
            if(i*prime[j]>MaxN) break ;
            Not_p[i*prime[j]]=1;
            mobius[i*prime[j]]=mobius[i]*mobius[prime[j]];
            if(!(i%prime[j])){mobius[i*prime[j]]=0; break ;}
        }
    }
    //for(int i=1;i<=10;i++) printf("%d ",mobius[i]);
    for(int i=1;i<=cnt;i++)
        for(int j=1;j*prime[i]<=MaxN;j++) sum[prime[i]*j]+=mobius[j];
    for(int i=1;i<=MaxN;i++) Pre[i]=Pre[i-1]+sum[i];
}
void Solve()
{
    Prime_Ini();
    T=read();
    while(T--)
    {
        ll ans=0;
        n=read(); m=read();
        if(n>m) swap(n,m);
        ll last=0;
        for(ll i=1;i<=n;i=last+1ll)
        {
            last=min((n/(n/i)),(m/(m/i)));
            ans+=(n/i)*(m/i)*(Pre[last]-Pre[i-1]);
        }
        printf("%lld\n",ans);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}