#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=10000;
int n,V;
int v[Maxn];
int w[Maxn];
int s[Maxn];
int A[Maxn];
void Make_goods()
{
    int in=n;
    for(int i=1;i<=in;i++)
    {
        if(s[i]>0)
        {
            int j=2; s[i]--;
            while(s[i]-j>=0) v[++n]=j*v[i],w[n]=j*w[i],s[n]=-1,j<<=1;
            if(s[i]>0) v[++n]=s[i]*v[i],w[n]=s[i]*w[i],s[n]=-1;
            s[i]=-1;
        }
    }
}
void Solve()
{
    scanf("%d%d",&n,&V);
    for(int i=1;i<=n;i++) scanf("%d%d%d",&v[i],&w[i],&s[i]);
    Make_goods();    
    for(int i=1;i<=n;i++)
    {
        if(!s[i]) for(int j=v[i];j<=V;j++) A[j]=max(A[j],A[j-v[i]]+w[i]);
        else for(int j=V;j>=v[i];j--) A[j]=max(A[j],A[j-v[i]]+w[i]);
    }
    printf("%d",A[V]);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}