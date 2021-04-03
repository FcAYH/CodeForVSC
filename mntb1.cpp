#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int Maxn=5005;
int a[Maxn];
int t,n,i,s;
void Solve()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        s=1;
        a[1]=s;
        for(i=2;i<=n;i+=2) a[i]=++s;
        s=n;
        for(i=3;i<=n;i+=2) a[i]=s--;
        for(i=1;i<n;i++) printf("%d ",a[i]);
        printf("%d\n",a[i]);
    }
}
int main()
{
    freopen("drift10.in","r",stdin);
    freopen("drift10.out","w",stdout);
    Solve();
    //system("pause");
    return 0;
}
