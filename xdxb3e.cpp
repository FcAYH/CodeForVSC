#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stack>
typedef long long ll;
using namespace std;
const int Maxn=2e5+5;
const int Inf=0x3f3f3f3f;
struct EDGE{int to,next,v;}E[Maxn];
int num=0,n,m;
int head[Maxn];
int dis[Maxn];
int vis[Maxn];
void add_edge(int x,int y,int vt) 
{
	E[++num].next=head[x],E[num].to=y,E[num].v=vt,head[x]=num;
}
void spfa() 
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
	stack<int> q;
	q.push(1); dis[1]=0,vis[1]=1;
	while(!q.empty()) 
    {
		int st=q.top();q.pop();
		vis[st]=0;
		for(int i=head[st];i!=0;i=E[i].next) 
        {
			int qt=E[i].to,val=E[i].v;
			if(dis[qt]>dis[st]+val) 
            {
				dis[qt]=dis[st]+val;
				if(vis[qt]==0) vis[qt]=1,q.push(qt);
			}			
		}		
	}	
}
void Solve()
{
    scanf("%d%d",&n,&m);
    int u,v,w;
    for(int i = 1; i<=m; i++) scanf("%d%d%d",&u,&v,&w),add_edge(u,v,w);
    spfa();
    printf("%d\n",dis[n]);		
}
int main()
{
    Solve();
	system("pause");
    return 0 ;
}
