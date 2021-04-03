#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
ll n,m,k;
void Solve()
{
    cin>>n>>m>>k;
    if((2*n*m)%k) printf("NO\n");
    else
    {
        for(register ll x=1ll;x<=sqrt(2ll*n*m/k);x++)
        {
            ll y=(2ll*n*m/k)/x;
            ll b=(2ll*n*m/k)-x*y;
            if(x<=n&&y<=m&&b<=x)
            {
                cout<<"YES"<<endl;
                cout<<"0"<<" "<<"0"<<endl;
                cout<<x<<" "<<"1"<<endl;
                cout<<b<<" "<<y<<endl;
                return ;
            }
        }
        for(register ll y=1ll;y<=sqrt(2ll*n*m/k);y++)
        {
            ll x=(2ll*n*m/k)/y;
            ll b=(2ll*n*m/k)-x*y;
            if(x<=n&&y<=m&&b<=x)
            {
                cout<<"YES"<<endl;
                cout<<"0"<<" "<<"0"<<endl;
                cout<<x<<" "<<"1"<<endl;
                cout<<b<<" "<<y<<endl;
                return ;
            }
        }
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}