#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod=998244353;
const int Maxn=1010;
const int MaxD=20011;
int n;
int Maxd=0;
int sl[Maxn];
ll A[Maxn][MaxD];
ll ans=0;
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Solve()
{
    n=read();
    for(int i=1;i<=n;i++) sl[i]=read(),Maxd=max(Maxd,sl[i]);
    for(int i=2;i<=n;i++)
        for(int j=1;j<i;j++) if(sl[i]>=sl[j]) A[i][sl[i]-sl[j]]++;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++) 
            if(sl[i]>=sl[j]) A[i][sl[i]-sl[j]]+=A[j][sl[i]-sl[j]],A[i][sl[i]-sl[j]]%=Mod;
    }
    ans=(ll)n;
    for(int i=1;i<=n;i++)
        for(int d=0;d<=Maxd;d++) ans+=A[i][d],ans%=Mod;
    memset(A,0,sizeof(A));
    for(int i=n-1;i>=1;i--)
        for(int j=n;j>i;j--) if(sl[i]>sl[j]) A[i][sl[i]-sl[j]]++;
    for(int i=n-1;i>=1;i--)
    {
        for(int j=n;j>i;j--) 
            if(sl[i]>sl[j]) A[i][sl[i]-sl[j]]+=A[j][sl[i]-sl[j]],A[i][sl[i]-sl[j]]%=Mod;
    }
    for(int i=1;i<=n;i++)
        for(int d=0;d<=Maxd;d++) ans+=A[i][d],ans%=Mod;
    printf("%lld",ans);
}  
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
3
2 1 3

3 
3 2 1

8
13 14 6 20 27 34 34 41 
*/