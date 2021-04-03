#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=100020;
struct EDGE{int next,to;}E[Maxn<<2];
int n,cnt=0,num=0;
int Maxd=1;
int head[Maxn];
int fa[Maxn];
int depth[Maxn];
int Ans[Maxn];
inline void add_edge(int x,int y)
{
    if(x==-1) return ;
    E[++num].next=head[x],E[num].to=y,head[x]=num;
}
void dfs(int poi)
{
    for(int i=head[poi];i;i=E[i].next)
    {
        int qt=E[i].to;
        depth[qt]=depth[poi]+1;
        Maxd=max(Maxd,depth[qt]);
        dfs(qt);
    }
}

void Solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&fa[i]),add_edge(fa[i],i);
    for(int i=1;i<=n;i++) if(fa[i]==-1) depth[i]=1,dfs(i);
    printf("%d\n",Maxd);
    for(int i=1;i<=n;i++) if(depth[i]==Maxd) Ans[++cnt]=i;
    for(int i=1;i<cnt;i++) printf("%d ",Ans[i]);
    printf("%d",Ans[cnt]);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}