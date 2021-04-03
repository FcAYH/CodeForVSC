#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const ll Mod=998244353ll;
const int Maxn=6000010;
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
        if(b&1) ret*=a; a*=a,b>>=1; a%=Mod,ret%=Mod;
    }
    return ret;
}

bool Not_p[10000010];
int prime[10000010];
int len=0;
void Prime_Ini()
{
    Not_p[1]=1;
    for(int i=2;i<=10000000;i++)
    {
        if(!Not_p[i]) prime[++len]=i;
        for(int j=1;j<=len;j++)
        {
            if(prime[j]*i>10000000) break ;
            Not_p[i*prime[j]]=1;
            if(!(i%prime[j])) break ;
        }
    }
}

int a,b,c,d,x,y;
int cntx=0,cnty=0,num=0;
struct Wdnmd{int v,c;}Prix[Maxn],Priy[Maxn];
struct TheSame{ll v,att,x,y;}Same[Maxn]; 


void Solve()
{
    Prime_Ini();
    scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&x,&y);
    for(int i=1;i<=len;i++)
    {
        if(!(x%prime[i])) Prix[++cntx].v=prime[i];
        while(!(x%prime[i])) x/=prime[i],Prix[cntx].c++;
        if(x==1) break ;
    }
    if(x!=1) Prix[++cntx].v=x,Prix[cntx].c=1;
    for(int i=1;i<=len;i++)
    {
        if(!(y%prime[i])) Priy[++cnty].v=prime[i];
        while(!(y%prime[i])) y/=prime[i],Priy[cnty].c++;
        if(y==1) break ;
    }
    if(y!=1) Prix[++cnty].v=y,Prix[cnty].c=1;
    for(int i=1;i<=cntx;i++)
    {
        for(int j=1;j<=cnty;j++)
        {
            if(Prix[i].v==Priy[j].v)
            {
                Same[++num].v=Prix[i].v;
                Same[num].x=Prix[i].c;
                Same[num].y=Priy[j].c;
            }
            if(Priy[j].v>Prix[i].v) break ;
        }
    }
    //printf("%lld ",Same[1].y);
    for(int i=a;i<=b;i++)
    {
        for(int j=1;j<=num;j++)
        {
            ll boder=Same[j].x*i/Same[j].y;
            if(boder<c) Same[j].att+=Same[j].x*i*(d-c+1),Same[j].att%=Mod-1;
            else if(boder>d) Same[j].att+=Same[j].y*(c+d)*(d-c+1)/2ll,Same[j].att%=Mod-1;
            else
            {
                Same[j].att+=Same[j].y*(c+boder)*(boder-c+1ll)/2ll;
                Same[j].att+=Same[j].x*i*(d-boder);
                Same[j].att%=Mod-1;
            }
        }
    }
    ll ans=1ll;
    for(int i=1;i<=num;i++) ans*=Quick_Pow(Same[i].v,Same[i].att),ans%=Mod;
    cout<<ans<<endl;
}
signed main()
{
    //freopen("data.in","r",stdin);
    //freopen("My.out","w",stdout);
    Solve();
    system("pause");
    return 0;
}
//0 2 0 4 120 180
//0 2 0 3 120 180
//0 2 0 2 120 180
//0 8 0 2 14 7