#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MaxN=2999+1;
const int Maxn=2999*2+1;
const int Mod=100000007;
int n;
ll h[Maxn];
int C[Maxn][3010];
int Inv[MaxN];
void Ini()
{
    //Inv[1]=1ll;
	//for(int i=2;i<=MaxN;i++) Inv[i]=Mod-(Mod/i)*Inv[Mod%i]%Mod;
    C[0][0]=1,C[1][1]=1;
    for(int i=1;i<=MaxN;i++) C[i][0]=1;
    for(int i=2;i<Maxn;i++)
        for(int j=1;j<=min(i,3001);j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
}

inline int Quick_pow(ll a,ll b)
{
    ll ret=1;
    while(b>=1)
    {
        if(b&1) ret*=a; a=a*a, b>>=1; ret%=Mod,a%=Mod;
    }
    return ret;
}
inline ll M_Inv(ll x){ return Quick_pow(x,Mod-2ll);}
void Solve()
{
    Ini();
    scanf("%d",&n);
    printf("%lld\n",(M_Inv((ll)n+1ll)*C[2*n][n])%Mod);
    //printf("%d",(Inv[n+1]*C[2*n][n])%Mod);
}

int main()
{
   
    Solve();
    system("pause");
    return 0;
}