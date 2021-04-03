#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int Maxn=10000;
int n;
ll A[Maxn];
inline int Check_Prime(int x)
{
    for(int i=2;i<=sqrt(x);i++) if(!(x%i)) return 0;
    return 1;
}
void Solve()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        if(Check_Prime(i))
        {
            A[i]+=1ll;
            for(int j=i;j<=n;j++) A[j]+=A[j-i];
        }
    }
    printf("%lld\n",A[n]);
}
int main()
{
    Solve();

    return 0;
}
