#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Maxn=200000;
const int Maxm=400100;
int n,m,Q,num=0;
int head[Maxn];
int vis[Maxn];
int A[Maxn];
struct EDGE{int next,to,v;}E[Maxm];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
inline void add_edge(int x,int y,int vt)
{
    E[++num].next=head[x],E[num].to=y,E[num].v=vt,head[x]=num;
}
void Dfs(int poi)
{
    for(int i=head[poi];i;i=E[i].next)
    {
        int qt=E[i].to;
        if(vis[qt]) continue ;
        A[qt]=A[poi]^E[i].v,vis[qt]=1;
        Dfs(qt);
    }
}
void Solve()
{
    n=read(),m=read(),Q=read();
    int u,v,w,x,y;
    for(int i=1;i<=m;i++)
    {
        u=read(),v=read(),w=read();
        add_edge(u,v,w),add_edge(v,u,w);
    }
    A[1]=0,vis[1]=1;
    Dfs(1);
    for(int i=1;i<=Q;i++)
    {
        x=read(),y=read();
        printf("%d\n",A[x]^A[y]);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}