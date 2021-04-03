#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int Maxm=110000;
const int Maxn=10001;
const int Inf=0x3f3f3f3f;
int n,s,t,m,num=1;
int head[Maxn];
int vis[Maxn];
int dis[Maxn];
int Prep[Maxn];
int Pree[Maxn];
struct EDGE
{
int to,next,flow,cost;
};
EDGE E[Maxm];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
inline void add_edge(int x,int y,int vt,int cs)
{
    E[++num].next=head[x];
    E[num].to=y;
    E[num].flow=vt;
    E[num].cost=cs;
    head[x]=num;
    E[++num].next=head[y];
    E[num].to=x;
    E[num].flow=0;
    E[num].cost=-cs;
    head[y]=num;
}
inline bool Spfa()
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    queue<int> Q;
    Q.push(s); vis[s]=1; dis[s]=0;
    while(!Q.empty())
    {
        int st=Q.front(); Q.pop();
        vis[st]=0;
        for(int i=head[st];i;i=E[i].next)
        {
            int qt=E[i].to;
            if(E[i].flow>=1&&dis[qt]>dis[st]+E[i].cost)
            {
                dis[qt]=dis[st]+E[i].cost;
                Prep[qt]=st; Pree[qt]=i;
                if(!vis[qt]) vis[qt]=1,Q.push(qt);
            }
        }
    }
    if(dis[t]!=Inf) return true;
	return false; 
}
void Mfmc()
{
    int Min=0,Max=0,Ad; 
    while(Spfa()!=false)
    {
        Ad=Inf;
        for(int i=t;i!=s;i=Prep[i])
        {
        	cout<<i<<endl;
        	Ad=min(Ad,E[Pree[i]].flow);
		}
            
        Min+=dis[t]*Ad;
        Max+=Ad;
        for(int i=t;i!=s;i=Prep[i])
        {
            E[Pree[i]].flow-=Ad;
            E[Pree[i]^1].flow+=Ad;
        }
    }
    printf("%d %d\n",Max,Min);
}
void read_ini()
{
    n=read(); m=read(); s=read(); t=read();
    int u,v,w,f;
	for(int i=1;i<=m;i++) 
    {
        u=read(); v=read(); w=read(); f=read();
        add_edge(u,v,w,f);
    }
}
int main()
{
    read_ini();
    Mfmc();
    return 0;
}