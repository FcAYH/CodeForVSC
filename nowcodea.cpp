#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Maxn=200000;
typedef long long ll;
int n;
ll A[Maxn];
ll B[Maxn];
void Solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&A[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&B[i]);
    sort(A+1,A+1+n);
    sort(B+1,B+1+n);
    ll ans=0;
    for(int i=1;i<=n;i++) ans+=max(0ll,B[n-i+1]-A[i]);
    printf("%lld\n",ans);   
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
5
1 7 9 5 3
10 4 2 6 8

1 3 5 7 9
10 8 6 4 2
*/