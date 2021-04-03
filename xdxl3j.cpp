#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Inf=0x3f3f3f3f;
const int Maxn=10001;
struct Point{int x,y;}p[Maxn];
int n,cnt=0;
int vis[Maxn][5];
void Simulate()
{
    memset(vis,0,sizeof(vis));
    int nowx=0,nowy=0,nowh=1;
    while(1)
    {
        int next=0;
        if(nowh==1)
        {
            p[0].x=Inf,p[0].y=Inf;
            for(int i=1;i<=n;i++) 
            {
                if(p[i].y==nowy&&p[i].x>nowx&&p[i].x<p[next].x) next=i; 
            }
            if(!next) return ;
            if(vis[next][1]){cnt=-1; return ;}
            cnt++,vis[next][1]=1;
            nowx=p[next].x-1,nowh=2;
        }
        else if(nowh==2)
        {
            p[0].x=Inf,p[0].y=-Inf;
            for(int i=1;i<=n;i++)
            {
                if(p[i].x==nowx&&p[i].y<nowy&&p[i].y>p[next].y) next=i;
            }
            if(!next) return ;
            if(vis[next][2]){cnt=-1; return ;}
            cnt++,vis[next][2]=1;
            nowy=p[next].y+1,nowh=3;
        }
        else if(nowh==3)
        {
            p[0].x=-Inf,p[0].y=Inf;
            for(int i=1;i<=n;i++)
            {
                if(p[i].y==nowy&&p[i].x<=nowx&&p[i].x>p[next].x) next=i;
            }
            if(!next) return ;
            if(vis[next][3]){cnt=-1; return ;}
            cnt++,vis[next][3]=1;
            nowx=p[next].x+1,nowh=4;
        }
        else if(nowh==4)
        {
            p[0].x=Inf,p[0].y=Inf;
            for(int i=1;i<=n;i++)
            {
                if(p[i].x==nowx&&p[i].y>nowy&&p[i].y<p[next].y) next=i;
            }
            if(!next) return ;
            if(vis[next][4]){cnt=-1; return ;}
            cnt++,vis[next][4]=1;
            nowy=p[next].y-1;nowh=1;
        }
    }
}
void Solve()
{
    while(scanf("%d",&n)!=EOF)
    {
        cnt=0;
        for(int i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y);
        Simulate();
        printf("%d\n",cnt);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
        4
    3   p   1
        2
*/