#include<bits/stdc++.h>
using namespace std;
const int Maxn=20000;
int N;
int fa[Maxn];
int vis[Maxn];
inline int find(int x)
{
    return (fa[x]==x)?x:fa[x]=find(fa[x]);
}
inline void Merge(int x,int y){fa[y]=x;}
inline int cmp(int a,int b){return a<b;}
void Solve()
{
    for(int i=1;i<=10000;i++) fa[i]=i;
    scanf("%d",&N);
    int MaxN=-1;
    int x,y,k;
    for(int i=1;i<=N;i++)
    {
        scanf("%d%d",&k,&x);
        MaxN=max(MaxN,x);
        for(int j=2;j<=k;j++) 
        {
            scanf("%d",&y);
            MaxN=max(MaxN,y);
            int t1=find(x),t2=find(y);
            if(t1!=t2) Merge(t1,t2);
        }
    }
    for(int i=1;i<=MaxN;i++) vis[i]=find(find(fa[i]));
    sort(vis+1,vis+1+MaxN,cmp);
    printf("%d ",MaxN);
    int cnt=1;
    for(int i=2;i<=MaxN;i++) if(vis[i]!=vis[i-1]) cnt++;
    printf("%d\n",cnt);
    int Q;
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++) 
    {
        scanf("%d%d",&x,&y);
        int t1=find(x),t2=find(y);
        (t1==t2)?printf("Y\n"):printf("N\n");
    }
}
int main()
{
    Solve();
    //system("pause");
    return 0;
}