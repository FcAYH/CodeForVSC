#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;
const int Inf=0x3f3f3f3f;
const int Maxn=2000;
int n,k;
int A[Maxn-1][1001][2];
int a[Maxn];
int b[Maxn];
inline int cmp(int a,int b){return a<b;}
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Solve()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        memset(A,0x3f,sizeof(A));
        for(int i=1;i<=n;i++) a[i]=read();
        sort(a+1,a+1+n,cmp);
        for(int i=2;i<=n;i++) b[i-1]=(a[i]-a[i-1])*(a[i]-a[i-1]);
        for(int i=1;i<=n-1;i++) A[i][1][1]=b[i],A[i][0][0]=0;
        for(int i=2;i<=n-1;i++)
        {
            for(int j=1;j<=k;j++)
            {
                A[i][j][1]=min(A[i][j][1],A[i-1][j-1][0]+b[i]);
                A[i][j][0]=min(A[i][j][0],min(A[i-1][j][0],A[i-1][j][1]));
            }
        }
        printf("%d\n",min(A[n-1][k][0],A[n-1][k][1]));
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
6 2
1 2  100 120  11111 11113

*/