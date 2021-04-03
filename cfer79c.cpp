#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Maxn=101010;
int t,n,m,hav=0;
long long ans=0ll;
struct Gift{int id,send;}a[Maxn];
int b[Maxn];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
inline int cmp(Gift a,Gift b){return a.send<b.send;}
void Solve()
{
    t=read();
    while(t--)
    {
        ans=0ll; hav=0;
        memset(a,0,sizeof(a));
        n=read(); m=read();
        int ia;
        for(int i=1;i<=n;i++) ia=read(),a[ia].id=i;
        for(int i=1;i<=m;i++) b[i]=read();
        for(int i=1;i<=m;i++) a[b[i]].send=i;
        sort(a+1,a+1+n,cmp);
        int Maxdeep=0;
        for(int i=1;i<=n;i++)
        {
            if(!a[i].send) continue ;
            else
            {
                if(a[i].id<Maxdeep) ans++;
                else Maxdeep=a[i].id,ans+=(long long)(a[i].id-1-hav)*2ll+1ll;
                hav++;
            }
        }
        printf("%lld\n",ans);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
6
3 3
3 1 2
3 2 1
7 2
2 1 7 3 4 5 6
3 1
5 5
2 3 1 4 5
5 4 3 2 1
5 5
2 3 5 1 4
5 4 3 2 1
10 1
1 2 3 4 5 6 7 8 9 10
3
3 3
1 2 3
2 1 3

*/