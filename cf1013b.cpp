#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=100010;
int ans=3;
int n,x;
int a[Maxn];
int vis[Maxn];
void Solve()
{
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),vis[a[i]]++;
    for(int i=1;i<=n;i++) if(vis[a[i]]>1){printf("0"); return ;}
    for(int i=1;i<=n;i++)
    {
        if(vis[a[i]&x]&&(a[i]&x)!=a[i]) ans=min(ans,vis[a[i]&x]);
        else if(!vis[a[i]&x]) vis[a[i]&x]=2;
    }
    (ans!=3)?printf("%d",ans):printf("-1");
}
int main()
{
    Solve();
    system("pause");
    return 0;
}