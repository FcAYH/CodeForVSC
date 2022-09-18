#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=2000000;
const int Maxm=2000000;
int t,n,m,num=0;
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
void Solve()
{
    t=read();
    while(t--)
    {
        n=read(); m=read();
        int u,v,q,ope;
        for(int i=1;i<=m;i++)
        {
            u=read(),v=read(),add_edge(u,v),add_edge(v,u);
        }
        q=read();
        for(int i=1;i<=q;i++)
        {
            ope=read();
        }
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}