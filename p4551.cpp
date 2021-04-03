#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=1000001;
int N,num=0,tot=0;
int head[Maxn];
int vis[Maxn];
int Val[Maxn];
int Trie[Maxn][2];
struct EDGE{int next,to,v;}E[Maxn<<1];
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
void dfs(int poi)
{
    for(int i=head[poi];i;i=E[i].next)
    {
        int qt=E[i].to,val=E[i].v;
        if(!vis[qt]) 
        {
            Val[qt]=val^Val[poi];
            vis[qt]=1,dfs(qt);
        }
    }
}
inline void Insert(int x)
{
    int Temp[32];
    memset(Temp,0,sizeof(Temp));
    for(int i=1;i<=31;i++) if(x) Temp[i]=x%2,x>>=1;
    int root=0;
    for(int i=31;i>=1;i--)
    {
        if(Temp[i]) 
        {
            if(Trie[root][1]) root=Trie[root][1];
            else Trie[root][1]=++tot,root=tot;
        }
        else
        {
            if(Trie[root][0]) root=Trie[root][0];
            else Trie[root][0]=++tot,root=tot;
        }
    }
}
inline int Find_Ans(int x)
{
    int Temp[32],ret=x;
    memset(Temp,0,sizeof(Temp));
    for(int i=1;i<=31;i++) if(x) Temp[i]=x%2,x>>=1;
    int root=0;
    for(int i=31;i>=1;i--)
    {
        if(Temp[i])
        {
            if(Trie[root][0]) root=Trie[root][0];
            else root=Trie[root][1],ret^=1<<(i-1);
        }
        else
        {
            if(Trie[root][1]) root=Trie[root][1],ret^=1<<(i-1);
            else root=Trie[root][0];
        }
    }
    return ret;
}
void Solve()
{
    N=read();
    int u,v,w;
    for(int i=1;i<N;i++)
    {
        u=read(),v=read(),w=read();
        add_edge(u,v,w); add_edge(v,u,w);
    }
    vis[1]=1;
    dfs(1);
    int ans=0;
    //memset(Trie,0,sizeof(Trie));
    for(int i=1;i<=N;i++) Insert(Val[i]);
    for(int i=1;i<=N;i++) ans=max(ans,Find_Ans(Val[i]));
    printf("%d",ans);
}
int main()
{
    //freopen("P4551_10.in","r",stdin);
    //freopen("P4551_10.out","w",stdout);
    Solve();
    //system("pause");
    return 0;
}