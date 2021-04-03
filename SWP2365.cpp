#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll Mod=1000000007;
const int Maxn=1010;
int n,T,k;
ll ans=0;
ll A[Maxn][Maxn];
inline int read()
{
	int fl=1,rt=0; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') fl=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0';ch=getchar();}
	return fl*rt;
}
void Dynamic_P()
{
    memset(A,0ll,sizeof(A));
    for(int j=0;j<=k;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(j==0) 
            {
                if(i==1) A[i][j]=1ll;
                else if(i==2) A[i][j]=A[i-1][j];
                else if(i==3) A[i][j]=A[i-1][j]+A[i-2][j];
                else A[i][j]=A[i-1][j]+A[i-2][j]+A[i-3][j];
            }
            else 
            {
                if(i==1) A[i][j]=A[i+1][j-1];
                else if(i==2) A[i][j]=A[i-1][j]+A[i+1][j-1];
                else if(i==3) A[i][j]=A[i-1][j]+A[i-2][j]+A[i+1][j-1];
                else A[i][j]=A[i-1][j]+A[i-2][j]+A[i-3][j]+A[i+1][j-1];
            }
            A[i][j]%=Mod;
        }
    }
}
void Solve()
{
    T=read();
    while(T--)
    {
        ans=0;
        n=read(),k=read();
        Dynamic_P();
        for(int i=0;i<=k;i++) ans+=A[n][i],ans%=Mod;
        printf("%lld\n",ans);
    }
}
int main()
{
    Solve();
    //system("pause");
    return 0;
}
