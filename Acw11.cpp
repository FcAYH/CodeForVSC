#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod=1000000007;
const int MaxW=2000000;
const int Maxn=2000;
int n,V;
int v[Maxn],w[Maxn];
int A[Maxn];
ll Cnt[MaxW];
void Solve()
{
    scanf("%d%d",&n,&V);
    for(int i=1;i<=n;i++) scanf("%d%d",&v[i],&w[i]);
    for(int i=0;i<=V;i++) Cnt[i]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=V;j>=v[i];j--)
        {
            if(A[j-v[i]]+w[i]==A[j]) Cnt[j]+=Cnt[j-v[i]],Cnt[j]%=Mod;
            if(A[j-v[i]]+w[i]>A[j])
            {
                A[j]=A[j-v[i]]+w[i]; Cnt[j]=Cnt[j-v[i]],Cnt[j]%=Mod;
            }
        }
    }
    printf("%lld\n",Cnt[V]%Mod);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
10 100
2 1
3 9
14 16
27 67
22 65
31 45
18 35
27 65
13 29
33 85
*/