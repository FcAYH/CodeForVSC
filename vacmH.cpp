#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Maxn=3000;
int n,m,cnt=0;
int sl[Maxn];
int vis[Maxn];
int dur[Maxn];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
int cmp(int a,int b){return a>b;}
void Solve()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++) sl[i]=read();
    for(int i=1;i<=m;i++) dur[i]=read();
    sort(sl+1,sl+1+n,cmp);
    sort(dur+1,dur+1+m,cmp);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) if(dur[j]<sl[i]&&!vis[j]&&dur[j]>0){cnt++,vis[j]=1;break ;}
    }
    printf("%d\n",m-cnt);
}
int main()
{
    Solve();
    //system("pause");
    return 0;
}
/*
5 5
9
10
2
3
1

6
7
8
9
10

10 9 3 2 1
10 9 8 7 6
*/