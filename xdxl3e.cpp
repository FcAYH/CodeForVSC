#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int n,m,k;

void Solve()
{
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        ll ans=0ll;
        for(int i=1;i<=m;i++)
        {
            int il=(k-i-i)/2;
            if(il<=0) break ;
            ll line=(ll)(k-i-i)/2ll;
            if(line<n) ans+=(line*((ll)n-line)+line*(line+1ll)/2ll)*((ll)m-(ll)i+1ll);
            else ans+=((ll)n*(ll)(n+1ll)/2ll)*((ll)m-(ll)i+1ll);
        }
        cout<<ans<<endl;
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}