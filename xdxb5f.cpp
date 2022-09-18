#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxm=400010;
int n,num=0;
int depth[Maxm];
int head[Maxm];
struct EDGE{int next,to;}E[Maxm];
inline void add_edge(int x,int y)
{
    E[++num].next=head[x],E[num].to=y,head[x]=num;
}
void dfs(int poi,int fa)
{
    for(int i=head[poi];i;i=E[i].next)
    {
        int qt=E[i].to;
        if(qt==fa) continue;
        depth[qt]=depth[poi]+1;
        dfs(qt,poi);
    }
}
void Solve()
{
    scanf("%d",&n);
    int u,v;
    for(int i=1;i<=n-1;i++) scanf("%d%d",&u,&v),add_edge(u,v),add_edge(v,u);
    depth[1]=1;
    dfs(1,0);
    double ans=0;
    for(int i=1;i<=n;i++) ans+=1.0/(double)depth[i];
    printf("%.20lf",ans);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}