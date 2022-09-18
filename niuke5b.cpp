#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=100010;
const int Maxm=400010;
int n,num=1;
int ans=0;
int rec[Maxn];
int Tag[Maxn];
int iSum[Maxn];
int fa[Maxn];
int Num[32][Maxn];
int Cnt[40];
int vis[Maxm];
int VIS[Maxn];
int head[Maxn];
struct Point{int val,id;}P[Maxn];
struct EDGE{int next,v,to;}E[Maxm];
struct SBM{int v,id;}Sum[Maxn];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
inline int cmp(SBM a,SBM b){return a.v>b.v;}
inline int cmp2(Point a,Point b){return a.val>b.val;}
inline void add_edge(int x,int y,int vt)
{
    E[++num].next=head[x],E[num].to=y,E[num].v=vt,head[x]=num;
}
void Ini_()
{   
    int Nowc=(1<<30),temp=31;
    for(int i=0;i<=n-1;i++)
    {
        while((!(Sum[i].v&Nowc))&&temp) temp--,Nowc>>=1;
        Num[temp][++Cnt[temp]]=Sum[i].id;
    }
}
void dfs(int poi)
{
    for(int i=head[poi];i;i=E[i].next)
    {
        int qt=E[i].to,val=E[i].v;
        if(qt!=fa[poi])
        {
            rec[qt]=i;
            P[qt].id=qt,P[qt].val=val;
            Sum[qt].v=Sum[poi].v^val;
            Sum[qt].id=qt;
            fa[qt]=poi;
            dfs(qt);
        }
    }
}
inline int find(int poi)
{
    while(!Tag[poi]&&poi) poi=fa[poi];
    return poi;
}
void Greedy()
{
    for(int i=0;i<=n-1;i++)
    {
        int st=P[i].id;
        int t1=find(st);
        int VAL1=iSum[st]^iSum[t1]^iSum[Tag[t1]];
        int Nowc=(1<<30),temp=31;
        while((!(VAL1&Nowc))&&temp) temp--,Nowc>>=1;
        int qt=0,Min=(1<<30);
        //printf("%d %d %d",st,VAL1,temp);
        VIS[st]=1;
        for(int j=1;j<=Cnt[temp];j++)
        {
            if(VAL1^iSum[Num[temp][j]]<Min&&!VIS[Num[temp][j]]) 
            { 
                Min=VAL1^iSum[Num[temp][j]],qt=Num[temp][j];
            }
        }
        //printf("<%d> ",qt);puts("");
        if(Min>VAL1) continue ;
        vis[rec[st]]=1,vis[rec[st]^1]=1; 
        
        add_edge(st,qt,Min),add_edge(qt,st,Min);
        Tag[st]=qt;
    }
}
void Dfs(int poi,int f)
{
    for(int i=head[poi];i;i=E[i].next)
    {
        if(vis[i]) continue ;
        int qt=E[i].to;
        if(qt!=f)
        {
            ans+=E[i].v;
            Dfs(qt,poi);
        }
    }
}
void Solve()
{
    n=read();
    for(int i=1;i<n;i++) 
    {
        int u,v,w;
        u=read(),v=read(),w=read();
        add_edge(u,v,w),add_edge(v,u,w);
    }
    fa[0]=-1;
    dfs(0);
    /*
    printf("***\n");
    for(int i=0;i<n;i++) printf("%d ",Sum[i].v);
    printf("\n***\n");
    */
    for(int i=0;i<=n-1;i++) iSum[i]=Sum[i].v;
    sort(Sum,Sum+1+n-1,cmp);
    sort(P,P+1+n-1,cmp2);
    Ini_();
    Greedy();
    for(int i=1;i<=num;i++) if(!vis[i]) ans+=E[i].v;
    //Dfs(0,0);
    printf("%d",ans/2);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}