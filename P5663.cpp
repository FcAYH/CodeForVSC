#define debug(x) cout<<#x<<" "<<x<<endl;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Inf=0x3f3f3f3f;
const int Maxn=200000;
const int Maxm=300000;
int n,m,q,num=0;
int Left=1,Right=0;
int head[Maxn];
int vis[Maxn];
int odd[Maxn];
int even[Maxn];
int Q[Maxn*4];
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
inline int Check_empty(){return Left>Right?1:0;}
void Spfa()
{
    memset(odd,0x3f,sizeof(odd));
    memset(even,0x3f,sizeof(even));
    even[1]=0;
    Q[++Right]=1;
    while(!Check_empty())
    {
        int st=Q[Left++];
        vis[st]=0;
        for(int i=head[st];i;i=E[i].next)
        {
            int qt=E[i].to;
            if(odd[st]+1<even[qt]) 
            {
                even[qt]=odd[st]+1;
                if(!vis[qt]) Q[++Right]=qt,vis[qt]=1;
            }
            if(even[st]+1<odd[qt]) 
            {
                odd[qt]=even[st]+1;
                if(!vis[qt]) Q[++Right]=qt,vis[qt]=1;
            }
        }
    }    
}
void Print()
{
    for(int i=1;i<=n;i++) debug(odd[i]);
    for(int i=1;i<=n;i++) debug(even[i]);
}
void Solve()
{
    n=read(); m=read(); q=read();
    int u,v,a,L;
    for(int i=1;i<=m;i++) u=read(),v=read(),add_edge(u,v),add_edge(v,u);
    Spfa();
    //Print();
    for(int i=1;i<=q;i++)
    {
        a=read(); L=read();
        if(L%2) (odd[a]<=L)?printf("Yes\n"):printf("No\n");
        else (even[a]<=L)?printf("Yes\n"):printf("No\n");
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}