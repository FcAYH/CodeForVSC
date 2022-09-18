#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MaxN=1000000;
const int Maxn=1000100;
const ll Mod=23333333333333333;
int n,m,len=0;
ll Hash=0,Noh=0;
int ans=0;
ll h[Maxn];
ll c[Maxn];
ll l[Maxn];
ll a[Maxn];
void Solve()
{
    for(int i=1;i<=MaxN;i++) h[i]=i*1230;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%lld",&l[i]),len+=l[i];
    for(int i=1;i<=m;i++) scanf("%lld",&c[i]);
    for(int i=1;i<=m;i++) Hash+=(c[i]*l[i]*h[c[i]])%Mod; 
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=len;i++) Noh+=(a[i]*h[a[i]])%Mod;
    //printf("%lld <%lld>",Hash,Noh);
    if(Noh==Hash) ans++;
    for(int i=1;i<=n-len;i++)
    {
        Noh=(Noh-a[i]*h[a[i]]+Mod)%Mod;
        Noh+=(a[i+len]*h[a[i+len]])%Mod;
        if(Noh==Hash) ans++;
        //printf("<%lld>",Noh);
    }
    printf("%d",ans);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}