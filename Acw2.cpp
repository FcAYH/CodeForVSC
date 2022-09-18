#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=20000;
const int MaxV=20000;
int n,V;
int v[Maxn];
int s[Maxn];
int w[Maxn];
int A[MaxV];
void Make_goods()
{
    int in=n;
    for(int i=1;i<=in;i++)
    {
        s[i]--;
        for(int j=2;j<=s[i];j<<=1) v[++n]=j*v[i],w[n]=j*w[i],s[i]-=j;
        if(s[i]) v[++n]=s[i]*v[i],w[n]=s[i]*w[i];
    }
}
void Solve()
{
    scanf("%d%d",&n,&V);
    for(int i=1;i<=n;i++) scanf("%d%d%d",&v[i],&w[i],&s[i]);
    Make_goods();
    for(int i=1;i<=n;i++)
    {
        for(int j=V;j>=v[i];j--) A[j]=max(A[j],A[j-v[i]]+w[i]);
    }
    printf("%d",A[V]);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}