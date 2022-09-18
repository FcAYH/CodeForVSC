#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=1000000;
int t,n,m,cnt=0;
int Cnt[Maxn];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
inline void Work(int x,int y)
{
    for(int i=1;i<=y;i++) Cnt[++cnt]=y; 
    int a=x-y,b=y;
    if(a<b) swap(a,b);
    if(!b) return ;
    Work(a,b);
}
void Solve()
{
    t=read();
    while(t--)
    {
        cnt=0;
        n=read(),m=read();
        if(n<m) swap(n,m);
        Work(n,m);
        printf("%d\n",cnt);
        for(int i=1;i<=cnt;i++) printf("%d ",Cnt[i]);
        puts("");
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}