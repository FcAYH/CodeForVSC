#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=100000;
int n,fir,sec;
int a[Maxn];
void Solve()
{
    scanf("%d%d",&fir,&sec);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) 
    {
        if(a[i]<=1000) printf("%d %d\n",a[i],a[i]*fir);
        else printf("%d %d\n",a[i],1000*fir+sec*(a[i]-1000));
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}