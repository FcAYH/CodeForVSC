#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=100010;
int n,q,c;
int x[Maxn],y[Maxn],s[Maxn];
int Map[120][120][15];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Solve()
{
    n=read(),q=read(),c=read();
    for(int i=1;i<=n;i++) x[i]=read(),y[i]=read(),s[i]=read(),Map[x[i]][y[i]][s[i]]++;
    for(int xs=0;xs<=c;xs++)
    {
        for(int i=1;i<=100;i++)
        {
            for(int j=1;j<=100;j++)
            {
                Map[i][j][xs]+=Map[i-1][j][xs]+Map[i][j-1][xs]-Map[i-1][j-1][xs];
            }
        }
    }
    int T,X1,Y1,X2,Y2;
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d%d%d%d",&T,&X1,&Y1,&X2,&Y2);
        int ans=0;
        for(int xs=0;xs<=c;xs++)
        {
            int nowp=Map[X2][Y2][xs]-Map[X2][Y1-1][xs]-Map[X1-1][Y2][xs]+Map[X1-1][Y1-1][xs];
            int light=(xs+T)%(c+1);
            ans+=nowp*light;
        }
        printf("%d\n",ans);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}