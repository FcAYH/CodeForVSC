#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=100010;
ll Ans[Maxn];

void Solve()
{
    ll n;
    scanf("%lld",&n);
    ll ans=0ll;
    ans=n*(n-1)/2ll*(n-2)/3ll*(n-3)/4ll;
    printf("%lld",ans);
    /*
    while(n<=x)
    {
        ll l=1ll,r=(ll)n-3;
        for(int i=1;i<=n-3;i++) ans+=l*r,l++,r--;
        n++;
        printf("Ans[%d]=%lld;\n",n,ans);
    }
    */
}
int main()
{
    //freopen("biao.txt","w",stdout);
    Solve();
    system("pause");
    return 0;
}