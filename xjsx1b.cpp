#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int Maxn=2000001;
ll ans[Maxn];
ll a,b;
int cnt=0;
inline int cmp(ll a,ll b){return a<b;}
void Solve()
{
    scanf("%lld%lld",&a,&b);
    for(ll i=1;i<=sqrt(a);i++)
    {
        if(!(a%i)) 
        {
            if((!(i%b))&&i>=b) ans[++cnt]=i; 
            ll tmp=a/i;
            if((!((tmp)%b))&&(tmp!=i)&&tmp>=b) ans[++cnt]=tmp;
        }
    }
    sort(ans+1,ans+1+cnt,cmp);
    for(int i=1;i<=cnt;i++) printf("%lld ",ans[i]);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}