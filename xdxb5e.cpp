#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=400010;
const ll Mod=998244353ll;
int n;
char s[Maxn];
void Solve()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    ll l=2,r=n-1;
    while(s[l]==s[l-1]) l++;
    while(s[r]==s[r+1]) r--;
    ll ans=(l-1)+(n-r)+1;
    if(s[1]==s[n]) ans=(ans+(l-1)*(n-r))%Mod;
    printf("%lld",ans);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}