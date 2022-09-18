#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=202;
int t,n,m;
double a[Maxn][Maxn];
double Sum[Maxn][Maxn];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Solve()
{
    t=read();
    while(t--)
    {
        memset(Sum,0,sizeof(Sum));
        n=read(), m=read();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) a[i][j]=(double)read();
        for(int j=1;j<=m;j++)
        {
            for(int i=1;i<=n;i++) Sum[i][j]=Sum[i-1][j]+a[i][j];
        }       
        double Max=0.0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++) if(Sum[i][j]/a[i][j]>Max) Max=Sum[i][j]/a[i][j];
        }
        printf("%.8lf\n",Max);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}