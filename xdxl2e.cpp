#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int Maxm=999999;
typedef pair<int,int> pii;
priority_queue <pii,vector<pii>,greater<pii> > q; 
int n,m,s,t;
int dis[Maxm],head[Maxm],lim[Maxm];
bool vis[Maxm];
struct next_list
{
	int to,nxt,val;
}e[Maxm];

void add_edge(int u,int v,int val)
{
	e[++head[0]].to=v;
	e[head[0]].val=val;
	e[head[0]].nxt=head[u];
	head[u]=head[0];
}
int judge(int p,int k)
{
    if(k==0) return 0;
    int l=0,r=1e6,ans=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(k*mid<=p) ans=mid,l=mid+1;
        else r=mid-1;
    }
    return ans;
}
void Array_Ini()
{
    memset(head,0,sizeof(head));
    memset(vis,0,sizeof(vis));
    memset(lim,0,sizeof(lim));
    memset(e,0,sizeof(e));
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        Array_Ini();
        scanf("%d%d",&n,&m);
        for(int i=1;i<= n;i++) scanf("%d",&lim[i]);
        for(int i=1;i<=m;i++)
        {
            int u,v,val;
            scanf("%d%d%d",&u,&v,&val);
            add_edge(u, v, val),add_edge(v, u, val);
        }
        scanf("%d%d",&s,&t);
        for(int i=0;i<=n;i++) dis[i]=2147483647;
        dis[s]=0;
        q.push(make_pair(dis[s],s));
        while(!q.empty())
        {
            int x=q.top().second;
            q.pop();
            if(vis[x]) continue;
            vis[x]=1;
            for(int i=head[x];i;i=e[i].nxt)
            {
                int wait=judge(dis[x],lim[x]),d=0;
                if(wait%2==0) d=dis[x]+e[i].val;
                else d=(wait+1)*lim[x]+e[i].val;
                if(d<dis[e[i].to])
                {
                    dis[e[i].to]=d;
                    q.push(make_pair(dis[e[i].to],e[i].to));
                }
            }
        }
        printf("%d\n",dis[t]);
	}
    system("pause");
	return 0;
}
/*
1
9 14
3
5
7
3
5
7
9
3
5
1 2 4
1 8 8
2 3 8
2 8 11
3 4 7
3 6 4
3 9 2
4 5 9
4 6 14
5 6 10
6 7 2
7 9 6
7 8 1
8 9 7
1 5
*/