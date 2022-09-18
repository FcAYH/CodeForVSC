#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxm=40000;
const int Maxn=3000;
int n;
int num=0;
int Val[Maxn];
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
void dfs(int poi)
{
    for(int i=head[poi];i;i=E[i].next)
    {
        int qt=E[i].to;
        dfs(qt);
        Val[poi]+=Val[qt];
    }
    if(Val[poi]<0) Val[poi]=0;
}
void Solve()
{
    n=read();
    int m,s,p;
    for(int i=1;i<=n;i++)
    {
        m=read(),s=read(),p=read(); Val[i]=p-s;
        add_edge(m,i);//fa[i]=m;
    }
    dfs(0);
    printf("%d",Val[0]);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}