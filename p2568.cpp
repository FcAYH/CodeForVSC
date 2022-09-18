#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=10000010;
const int MaxN=10000000;
int n,cnt=0;
ll phi[Maxn];
int prime[Maxn];
int Not_p[Maxn];

void Prime_Ini()
{
    Not_p[1]=1; phi[1]=1;
    for(int i=2;i<=MaxN;i++)
    {
        if(!Not_p[i]) prime[++cnt]=i,phi[i]=i-1;
        for(int j=1;j<=cnt;j++)
        {
            if(i*prime[j]>MaxN) break ;
            Not_p[i*prime[j]]=1;
            phi[i*prime[j]]=phi[i]*phi[prime[j]];
            if(!(i%prime[j])) 
            {
                phi[i*prime[j]]=phi[i]*prime[j];
                break ;
            }
        }
    }
    for(int i=2;i<=MaxN;i++) phi[i]+=phi[i-1];
}
void Solve()
{
    Prime_Ini();
    scanf("%d",&n);
    ll ans=0ll;
    for(int i=1;i<=cnt;i++)
    {
        if(prime[i]>n) break ;
        ans+=2*(phi[n/prime[i]]-1)+1;
    }
    printf("%lld",ans);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}