#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
void Solve()
{
    int ans=0;
    for(int i=1;i<=100;i++) ans+=100%i;
    printf("%d\n",ans);
    scanf("%d%d",&n,&k);
    ll Ans=0;
    if(n>k) Ans+=k*(n-k);
    ll K=1ll,last=0,len=0;
    for(int i=1;i<=min(n,k);i=last+1)
    {
        ll nowd=k/(k/i);
        last=nowd,nowd-=len,len=last;
        Ans+=(2ll*((ll)k%last)+(nowd-1ll)*K)/2ll*nowd;
    }
    printf("%lld\n",Ans);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}