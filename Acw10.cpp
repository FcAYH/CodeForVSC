#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=200;
const int MaxV=200;
const int Maxm=200;
struct EDGE{int next,to;}E[Maxm];
int n,V,root=0,num=0;
int v[Maxn],w[Maxn];
int A[Maxn][MaxV];
int head[Maxn];
inline void add_edge(int x,int y)
{
    E[++num].next=head[x],E[num].to=y,head[x]=num;
}
inline void dfs(int poi)
{
    for(int i=head[poi];i;i=E[i].next)
    {
        int qt=E[i].to;
        dfs(qt);
        for(int j=V-v[poi];j>=0;j--)
        {
            for(int k=0;k<=j;k++) A[poi][j]=max(A[poi][j],A[poi][j-k]+A[qt][k]);
        }
    }
    for(int i=V;i>=v[poi];i--) A[poi][i]=A[poi][i-v[poi]]+w[poi];
    for(int i=0;i<v[poi];i++) A[poi][i]=0;
}
void Solve()
{
    scanf("%d%d",&n,&V);
    for(int i=1;i<=n;i++)
    {
        int p;
        scanf("%d%d%d",&v[i],&w[i],&p);
        add_edge(p,i); if(p==-1) root=i;
    }
    dfs(root);
    printf("%d",A[root][V]);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}