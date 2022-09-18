#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=1010;
int n,V,M;
int v[Maxn],w[Maxn],m[Maxn];
int A[Maxn][Maxn];
void Solve()
{
    scanf("%d%d%d",&n,&V,&M);
    for(int i=1;i<=n;i++) scanf("%d%d%d",&v[i],&m[i],&w[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=V;j>=v[i];j--)
            for(int k=M;k>=m[i];k--) A[j][k]=max(A[j][k],A[j-v[i]][k-m[i]]+w[i]);
    }
    printf("%d",A[V][M]);
    
}
int main()
{
    Solve();
    system("pause");
    return 0;
}