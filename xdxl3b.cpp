#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=100010;
int n;
ll a[Maxn];
ll ia[Maxn];
inline int cmp(ll a,ll b){return a<b;}
void Solve()
{
    while(scanf("%d",&n)!=EOF)
    {
        ll ans=0;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        ll Mod=10;
        for(int i=1;i<=10;i++)
        {
            for(int j=1;j<=n;j++) ia[j]=a[j]%Mod;
            sort(ia+1,ia+1+n,cmp);
            for(int j=1;j<=n;j++)
            {
                ll temp=Mod-ia[j];
                if(ia[n]>=temp)
                {
                    int nowp=lower_bound(ia+1,ia+1+n,temp)-ia;
                    if(nowp>j) ans+=(ll)n-(ll)nowp+1ll;
                    else ans+=(ll)n-(ll)j;
                }
            }
            Mod*=10ll;
        }
        printf("%lld\n",ans);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}