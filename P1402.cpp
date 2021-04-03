#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int Maxn=500;
const int Maxm=500000;
const int Inf=0x3f3f3f3f;
int n,m,s,t,num=1;
int depth[Maxn];
int head[Maxn];
int cur[Maxn];
struct EDGE
{
	int to,next;
    ll flow;
};
EDGE E[Maxm];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
inline void add_edge(int x,int y,int fl)
{
	E[++num].next=head[x];
	E[num].to=y;
	E[num].flow=fl;
	head[x]=num;	
	E[++num].next=head[y];
	E[num].to=x;
	E[num].flow=0;
	head[y]=num;
}
inline int dfs(int poi,ll dis)
{
	if(poi==t) return dis;
	ll used=0;
	for(int i=cur[poi];i;i=E[i].next)
	{
		int qt=E[i].to;
		if(E[i].flow>=1&&depth[qt]==depth[poi]+1)
		{
			ll Mer=dfs(qt,min(dis-used,E[i].flow));
			used+=Mer;
			E[i].flow-=Mer;
			E[i^1].flow+=Mer;
			if(E[i].flow) cur[poi]=i;
			if(used==dis) return used;
		}
	}
	if(used==0) cur[poi]=0;
	return used;
}
inline bool bfs()
{
	memset(depth,0,sizeof(depth));
	queue<int> Q;
	depth[s]=1;
	Q.push(s);
	while(!Q.empty())
	{
		int st=Q.front(); Q.pop();
		for(int i=head[st];i;i=E[i].next)
		{
			int qt=E[i].to;
			if(E[i].flow>=1&&!depth[qt])
			{
				depth[qt]=depth[st]+1;
				Q.push(qt);
			}
		}
	}
	if(!depth[t]) return false;
	return true;
}
void Dinic()
{
	ll Max=0;
	while(bfs()!=false)
	{
		memcpy(cur,head,sizeof head);
		ll Ad=0;
		Ad=dfs(s,Inf); Max+=Ad;
	}
	printf("%lld\n",Max);
}
void read_ini()
{
    n=read(); m=read(); s=read(); t=read();
    int u,v,w;
    for(int i=1;i<=m;i++) 
    {
        u=read(); v=read(); w=read();
        add_edge(u,v,w);
    }
	Dinic();
}
int main()
{
    freopen("P3376_7.in","r",stdin);
    freopen("P1402.out","w",stdout);
	read_ini();
	return 0;
}
/*
1 5 5
1 1 1 1 1
1 1 1 1 1
*/