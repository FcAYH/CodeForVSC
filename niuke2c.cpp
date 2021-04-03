#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Maxn=200010;
int n,num=0,cnt=0;
int in[Maxn];
int head[Maxn];
int Depth[Maxn];
struct EDGE{int next,to;}E[Maxn<<1];
struct SORT{int id,depth;}Sor[Maxn];
inline void add_edge(int x,int y)
{
    E[++num].next=head[x],E[num].to=y,head[x]=num;
}
inline int cmp(SORT a,SORT b){return a.depth<b.depth;}
void dfs(int poi,int fa)
{
    //iprintf("%d %d ",poi,fa);
    for(int i=head[poi];i;i=E[i].next)
    {
        int qt=E[i].to;
        if(qt!=fa) Depth[qt]=Depth[poi]+1,dfs(qt,poi);        
    }
}
void Solve()
{
    scanf("%d",&n);
    if(n==1)
    {
        printf("1\n1 1\n"); return ;
    }
    int u,v;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        if(n==2)
        {
            printf("1\n%d %d\n",u,v); return ;
        }
        add_edge(u,v),add_edge(v,u);
        in[u]++,in[v]++;
    }
    for(int i=1;i<=n;i++) 
    {
        if(in[i]>1) 
        {
            Depth[i]=1,dfs(i,0); break ;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(in[i]==1) Sor[++cnt].id=i,Sor[cnt].depth=Depth[i];
    }
    sort(Sor+1,Sor+1+cnt,cmp);
    if(!(cnt%2))
    {
        printf("%d\n",cnt/2);
        for(int i=1;i<=cnt/2;i++)
        {
            printf("%d %d\n",Sor[i].id,Sor[cnt-i+1].id);
        }
    }
    else
    {
        printf("%d\n",cnt/2+1);
        for(int i=1;i<=cnt/2;i++)
        {
            printf("%d %d\n",Sor[i].id,Sor[cnt-i+1].id);
        }
        printf("%d %d\n",Sor[cnt/2+1].id,Sor[cnt].id);
    }
    
    
}
int main()
{
    Solve();
    system("pause");
    return 0;
}