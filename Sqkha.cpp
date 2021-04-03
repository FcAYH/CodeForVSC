#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Maxn=1000;
int Ansx[Maxn],Ansy[Maxn];
int Tempx[Maxn],Tempy[Maxn];
int vis[10][10];
int Map[10][10];
int Min=100000;
int dx[]={0,0,0,-1,1};
int dy[]={0,1,-1,0,0};
void dfs(int x,int y,int step)
{
    if(x==5&&y==5)
    {
        if(step<Min) 
        {
            Min=step;
            for(int i=1;i<=step;i++) Ansx[i]=Tempx[i],Ansy[i]=Tempy[i]; 
        }
    }
    else
    {
        for(int i=1;i<=4;i++)
        {
            int tx=x+dx[i],ty=y+dy[i];
            if(!vis[tx][ty]&&tx>=1&&tx<=5&&ty>=1&&ty<=5&&Map[tx][ty]!=1)
            {
                vis[tx][ty]=1;
                Tempx[step+1]=tx,Tempy[step+1]=ty;
                dfs(tx,ty,step+1);
                vis[tx][ty]=0;
            }
        }
    }
    
}
void Solve()
{
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++) scanf("%d",&Map[i][j]);
    Ansx[0]=1,Ansy[0]=1;
    dfs(1,1,0);
    for(int i=0;i<=Min;i++) printf("(%d, %d)\n",Ansx[i]-1,Ansy[i]-1);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}