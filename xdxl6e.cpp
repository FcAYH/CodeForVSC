#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Inf=0x3f3f3f3f;
const int Maxn=200100;
int n;
int cost[Maxn],Next[Maxn];
int vis[Maxn],rec[Maxn];
int pre[Maxn];
int ans=0;
inline void dfs(int poi)
{
    if(rec[poi]) return ;
    if(vis[poi])
    {
        int nowp=Next[poi];
        int Minv=cost[nowp];
        while(nowp!=poi) nowp=Next[nowp],Minv=min(Minv,cost[nowp]);
        ans+=Minv;
    }
    else 
    {
        vis[poi]=1,dfs(Next[poi]);
    }
    vis[poi]=0,rec[poi]=1;
}
void Solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&cost[i]);
    for(int i=1;i<=n;i++) scanf("%d",&Next[i]);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]) dfs(i);
    }
    printf("%d",ans);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
5
1 2 3 2 10
1 3 4 3 3
*/