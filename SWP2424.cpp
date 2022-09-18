#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll Inf=0x38D7EA4C68000;
const int Maxn=300;
int n,T,m;
int Num[Maxn];
ll MaxN[Maxn][Maxn];
ll MinN[Maxn][Maxn];
ll A[Maxn][Maxn];
inline int read()
{
	int fl=1,rt=0; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') fl=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0';ch=getchar();}
	return fl*rt;
}
inline void Init()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int Max=-10001,Min=10001;
            for(int k=i;k<=j;k++) Max=max(Max,Num[k]),Min=min(Min,Num[k]);
            MaxN[i][j]=(ll)Max,MinN[i][j]=(ll)Min;
        }
    }
}
inline ll TPow(ll x){return x*x;}
inline void Dynamic_P()
{
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) A[i][j]=Inf;
    for(int i=1;i<=n;i++) A[i][1]=TPow(MaxN[1][i]-MinN[1][i]);
    for(int i=1;i<=n;i++)
    {
        for(int k=2;k<=m;k++)
        {
            for(int j=1;j<i;j++)
                A[i][k]=min(A[i][k],A[j][k-1]+TPow(MaxN[j+1][i]-MinN[j+1][i]));
        }
    }
}
void Solve()
{
    T=read();
    while(T--)
    {
        n=read(),m=read();
        for(int i=1;i<=n;i++) Num[i]=read();
        Init();
        Dynamic_P();
        ll ans=Inf;
        for(int i=1;i<=m;i++) ans=min(ans,A[n][i]);
        printf("%lld\n",ans);
    }
}
int main()
{
    Solve();
    //system("pause");
    return 0;
}