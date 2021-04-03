#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=200;
const int MaxV=200;
int n,V;
int s[Maxn];
int v[Maxn][Maxn];
int w[Maxn][Maxn];
int A[Maxn][MaxV];
void Solve()
{
    scanf("%d%d",&n,&V);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&s[i]);
        for(int j=1;j<=s[i];j++) scanf("%d%d",&v[i][j],&w[i][j]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=V;j>=0;j--)
        {
            for(int k=0;k<=s[i];k++)
            {
                if(j<v[i][k]) continue ;
                A[i][j]=max(A[i][j],A[i-1][j-v[i][k]]+w[i][k]);
            }
        }
    }
    printf("%d",A[n][V]);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}