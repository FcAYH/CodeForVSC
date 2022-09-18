#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
ll m,a,b,c;
void Solve()
{
    scanf("%lld%lld%lld%lld",&m,&a,&b,&c);
    ll sg1=a%(m+1);
    ll sg2=(b-1)%(m+1);
    ll sg3=(c-1)%(m+1);
    ((sg1^sg2^sg3)==0)?printf("Danftito"):printf("Tomaz");
}
int main()
{
    Solve();
    system("pause");
    return 0;
}