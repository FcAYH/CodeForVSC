#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
queue <int> q;
int n,m,s,t;
int head[660600],dis[606060],prep[606060],pree[606006];
bool vis[606600];
struct pro
{
	int to,nxt,val,flo;
}e[606600];
int read()
{
	int rt=0,in=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')	in=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0';ch=getchar();}
	return rt*in;
}
void add_edge(int u,int v,int flo,int val)
{
	e[++head[0]].to=v;
	e[head[0]].nxt=head[u];
	e[head[0]].val=val;
	e[head[0]].flo=flo;
	head[u]=head[0];
}
bool SPFA()
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    //printf("<%d %d> ", dis[0],0x3f3f3f3f);
    q.push(s),vis[s]=1,dis[s]=0;
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        vis[x]=0;
        for(int i=head[x]; i; i=e[i].nxt)
            if(e[i].flo>0&&dis[e[i].to]>dis[x]+e[i].val)
            {
                dis[e[i].to]=dis[x]+e[i].val;
                prep[e[i].to]=x; pree[e[i].to]=i;
                if(!vis[e[i].to])
            	{
	            	vis[e[i].to]=1;
	            	q.push(e[i].to);
	            }
            }
    }
    if(dis[t]!=0x3f3f3f3f) return true;
	return false; 
}
void MFMC()
{
	int Max=0,Min=0,ans=2e9;
	while(SPFA())
	{
        ans=2e9;//->
		for(int i=t; i!=s; i=prep[i])
		{
//			cout<<i<<endl;
			ans=min(ans,e[pree[i]].flo);
		}
            
        Min+=dis[t]*ans,Max+=ans;
        for(int i=t;i!=s;i=prep[i])
        {
            e[pree[i]].flo-=ans;
            e[pree[i]^1].flo+=ans;
        }
	}
	printf("%d %d\n",Max,Min);
}
int main()
{
	n=read(),m=read(),s=read(),t=read();
	head[0]=1;
	for(int i=1; i<=m; i++)
	{
		int u=read(),v=read(),flo=read(),val=read();
		add_edge(u,v,flo,val),add_edge(v,u,0,-val);
	}
	MFMC();

	return 0;
}