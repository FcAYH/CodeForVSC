#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=40;
int n,l;
ll num;
ll A[Maxn][Maxn];
ll dp[Maxn][Maxn];
ll Sum[Maxn][Maxn];
int Ans[Maxn];
void Array_Ini()
{
    A[0][0]=1,A[1][1]=1,A[1][0]=1;
    for(int i=2;i<=31;i++)
    {
        A[i][0]=1;
        for(int j=1;j<=i;j++) A[i][j]=A[i-1][j]+A[i-1][j-1];
    
    }
    for(int i=0;i<=31;i++)
    {
        for(int j=0;j<=31;j++)   
            for(int k=0;k<=j;k++) Sum[i][j]+=A[i][k];
    }
    //printf("%lld %lld ",Sum[2][2],Sum[1][2]);
    
}
inline void dfs(int Max,int len,ll x)
{
    ll s,last;
    for(int i=0;i<=Max;i++) 
    {
        last=s;
        s=0;
        for(int j=0;j<=len;j++)
        {
            s+=A[i][j];
            
            if(s>=x) 
            {
                Ans[i]=1;
                return dfs(Max-1,len-1,x-last);
            }
        }
    }
}
void Solve()
{
    Array_Ini();
    scanf("%d%d%lld",&n,&l,&num);
   
    dfs(n,l,num);
    int flag=0;
    for(int i=n;i>=1;i--) printf("%d",Ans[i]);
}
int main()
{
    Solve();
    //system("pause");
    return 0;
}