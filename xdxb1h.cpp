#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Maxp=10;
const int Maxm=40010;
struct EDGE{int next,to,v;}E[Maxm];
int ans=0,nowans=0,n,num=1;
int rec[Maxm];
int head[Maxp];
inline void add_edge(int x,int y,int vt)
{
    E[++num].next=head[x],E[num].to=y,E[num].v=vt,head[x]=num;
    E[++num].next=head[y],E[num].to=x,E[num].v=vt,head[y]=num;
}
void Array_Ini()
{
    nowans=0;
    memset(rec,0,sizeof(rec));
}
inline void dfs(int poi)
{
    for(int i=head[poi];i;i=E[i].next)
    {
        if(!rec[i])
        {
            int qt=E[i].to,val=E[i].v;
            rec[i]=1,rec[i^1]=1;
            nowans+=val;
            ans=max(ans,nowans);
            dfs(qt);
            nowans-=val;
            rec[i]=0,rec[i^1]=0;
        }
    }
}
void Solve()
{
    scanf("%d",&n);
    int u,v,w;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d%d",&u,&w,&v);
        add_edge(u,v,w);
    }
    for(int i=1;i<=4;i++) Array_Ini(),dfs(i);
    printf("%d",ans);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
4
1 2 1
1 3 1
1 4 1
1 5 1
*/