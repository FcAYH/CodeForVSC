#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,Ans;
ll phi(ll x)
{
    ll ans=x;
    for(ll i=2;i<=sqrt(x);i++)
    {
        if(!(x%i)) ans=ans/i*(i-1);
        while(!(x%i)) x/=i;
    }
    if(x>1) ans=ans/x*(x-1);
    return ans;
}
void Solve()
{
    scanf("%lld",&n);
    for(ll i=1;i<=sqrt(n);i++)
    {
        if(!(n%i)) 
        {
            (i!=n/i)?Ans+=i*phi(n/i),Ans+=(n/i)*phi(i):Ans+=(n/i)*phi(i);
        }
    }
    printf("%lld",Ans);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}