#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=1000000;
int n;
int a[Maxn];
int Mod1[10],Mod2[10];
int ans=0;
void Solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) a[i]+=a[i-1],a[i]%=7;
    int st=0,ed=0;
    memset(Mod1,0x3f,sizeof(Mod1));
    memset(Mod2,0,sizeof(Mod2));
    for(int i=1;i<=n;i++) Mod1[a[i]]=min(Mod1[a[i]],i);
    for(int i=n;i>=1;i--) Mod2[a[i]]=max(Mod2[a[i]],i);
    /*
    for(int i=1;i<=n;i++) printf("%d ",a[i]); puts("");
    for(int i=0;i<=6;i++) printf("%d ",Mod1[i]); puts("");
    for(int i=0;i<=6;i++) printf("%d ",Mod2[i]); puts("");
    */
    for(int i=0;i<=6;i++) ans=max(ans,Mod2[i]-Mod1[i]);
    printf("%d",ans);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}