#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const ll Mod=
void Solve()
{
    scanf("%lld%lld%lld",&n,&x,&d);
    a[1]=x;
    for(int i=2;i<=n;i++) a[i]=a[i-1]+d;
    ll in=n;
    for(int i=2;i<=n;i++) if(a[i]==0) in--;
    printf("%lld",Quick_Pow(in)); 

}
int main()
{
    Solve();
    system("pause");
    return 0;
}