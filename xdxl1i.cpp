#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=200;
int t,h,w,cnt=0;
char pic[Maxn][Maxn];
int vis[Maxn][Maxn];
inline void Make(int x,int y)
{
    if(pic[x][y]=='.') return ;
    switch(pic[x][y])
    {
        case 'O':
        {
            vis[x][y]=++cnt;
            if(pic[x+1][y]=='|') vis[x+1][y]=cnt;
            if(pic[x+1][y-1]=='/') vis[x+1][y-1]=cnt;
            if(pic[x+1][y+1]=='\\') vis[x+1][y+1]=cnt;
            if(pic[x+2][y-1]=='(') vis[x+2][y-1]=cnt;
            if(pic[x+2][y+1]==')') vis[x+2][y+1]=cnt;
            break ;
        }
        case '/':
        {
            vis[x][y]=++cnt;
            if(pic[x][y+1]=='|') vis[x][y+1]=cnt;
            if(pic[x][y+2]=='\\') vis[x][y+2]=cnt;
            if(pic[x+1][y]=='(') vis[x+1][y]=cnt;
            if(pic[x+1][y+2]==')') vis[x+1][y+2]=cnt;
            break ;
        }
        case '|':
        {
            vis[x][y]=++cnt;
            if(pic[x][y+1]=='\\') vis[x][y+1]=cnt;
            if(pic[x+1][y-1]=='(') vis[x+1][y-1]=cnt;
            if(pic[x+1][y+1]==')') vis[x+1][y+1]=cnt;
            break ;
        }
        case '\\':
        {
            vis[x][y]=++cnt;
            if(pic[x+1][y-2]=='(') vis[x+1][y-2]=cnt;
            if(pic[x+1][y]==')') vis[x+1][y]=cnt;
            break ;
        }
        case '(':
        {
            vis[x][y]=++cnt;
            if(pic[x][y+2]==')') vis[x][y+2]=cnt;
            break ;
        }
        case ')':
        {
            vis[x][y]=++cnt;
            break ;
        }
    }
}
void Solve()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        cnt=0;
        scanf("%d%d",&h,&w);
        for(int i=1;i<=h;i++) scanf("%s",pic[i]+1);
        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++) 
            {
                if(!vis[i][j]) Make(i,j);
            }
        }
        printf("%d\n",cnt);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}