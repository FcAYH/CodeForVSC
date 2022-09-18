#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod=80112002;
const int Maxn=6000;
const int Maxm=600000;
int n,m,num=0,ans=0,cnt=0;
int in[Maxn];
int out[Maxn];
int A[Maxn];
int q[Maxn*2];
int head[Maxn];
struct EDGE{int next,to;}E[Maxm];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
inline void add_edge(int x,int y)
{
    E[++num].next=head[x],E[num].to=y,head[x]=num;
}
void Topological_Sort()
{
    queue<int> Q;
    for(int i=1;i<=n;i++) if(!in[i]) A[i]=1,Q.push(i),q[++cnt]=i;
    while(!Q.empty()) 
    {
        int st=Q.front(); Q.pop();
        for(int i=head[st];i;i=E[i].next)
        {
            int qt=E[i].to;
            in[qt]--;
            if(!in[qt]) Q.push(qt),q[++cnt]=qt;
        }
    }
}
void Solve()
{
    n=read(), m=read();
    int u,v;
    for(int i=1;i<=m;i++) u=read(),v=read(),add_edge(u,v),in[v]++,out[u]++;
    Topological_Sort();
    for(int i=1;i<=cnt;i++)
    {
        int st=q[i];
        for(int j=head[st];j;j=E[j].next)
        {
            int qt=E[j].to;
            A[qt]=(A[qt]+A[st])%Mod;
        }
    }
    for(int i=1;i<=n;i++) if(!out[i]) ans=(ans+A[i])%Mod;
    printf("%d",ans);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}