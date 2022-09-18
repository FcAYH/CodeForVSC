#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod=998244353ll;
const int Maxm=1000010;
const int Maxn=400000;
int n,m,num=0;
ll sum=0,ans=1;
int head[Maxn];
int vis[Maxn];
int f[Maxn];
struct EDGE{int next,to;}E[Maxm];
inline void add_edge(int x,int y)
{
    E[++num].next=head[x],E[num].to=y,head[x]=num;
}
inline ll Quick_pow(ll a,ll b)
{
    ll ret=1;
    while(b>=1)
    {
        if(b&1) ret*=a; a=a*a,b>>=1; a%=Mod,ret%=Mod;
    }
    return ret;
}
inline void dfs(int poi,int fa)
{
    vis[poi]=1;
    for(int i=head[poi];i;i=E[i].next)
    {
        int qt=E[i].to;
        if(qt==fa) continue ;
        if(!vis[qt]) f[qt]=poi,dfs(qt,poi);
        else if(vis[qt]==1) 
        {
            int ip=poi,len=1;
            while(ip!=qt) ip=f[ip],len++;
            sum+=len;
            ans=(ans*(Quick_pow(2,len)-1))%Mod;
        }
    }
    vis[poi]=2;
}
inline void Array_Ini()
{
    num=0;
    memset(head,0,sizeof(head));
    memset(vis,0,sizeof(vis));
    sum=0,ans=1;
}
void Solve()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        Array_Ini();
        int u,v;
        for(int i=1;i<=m;i++) scanf("%d%d",&u,&v),add_edge(u,v),add_edge(v,u);
        for(int i=1;i<=n;i++) if(!vis[i]) dfs(i,0);
        ans=(Quick_pow(2,(m-sum))*ans)%Mod;
        printf("%lld\n",ans);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}