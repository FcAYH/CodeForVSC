#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Maxm=200010;
const int Maxn=300;
const ll Mod=1000000007;
int T,n,k;
ll a[Maxn];
ll A[Maxm*3];
void Dynamic_P()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=Maxm;j>=1;j--)
        {
            if(A[j]) A[j+a[i]]+=A[j],A[j+a[i]]%=Mod;
        }
        A[a[i]]++;A[a[i]]%=Mod;
    }
}
void Solve()
{
    cin>>T;
    while(T--)
    {
        memset(A,0,sizeof(A));
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        Dynamic_P();
        int qu;
        for(int i=1;i<=k;i++) 
        {
            cin>>qu;
            cout<<(A[qu]%Mod)<<endl;
        }
    }
}
int main()
{
    Solve();
    return 0;
}
/*
2
3 3
1 2 3
2 3 4

3 3
1 2 3
2 3 4

1
3 1
3 4 5
12
*/