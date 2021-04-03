#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int Maxn=101000;
int T[Maxn];
int A1[Maxn];
int A2[Maxn];
int b[Maxn];
int a[Maxn<<1];
int n,m,k;
void Insert(int x,int y)
{
    while(x<=10000) T[x]=max(T[x],y),x+=x&(-x);
}
inline int Search(int x)
{
    int ret=0;
    while(x>=1) ret=max(T[x],ret),x-=x&(-x);
    return ret;
}
int Work(int x)
{
    memset(T,0,sizeof(T));
    int cnt=0;
    for(int i=x+1;i<x+n;i++) if(a[i]!=10000) b[++cnt]=a[i];
    A1[1]=b[1];
    Insert(10000-b[1],b[1]);
    for(int i=2;i<=cnt;i++) A1[i]=Search(10000-b[i])+b[i],Insert(10000-b[i],A1[i]);
    memset(T,0,sizeof(T));
    A2[cnt]=b[cnt];
    Insert(10000-b[cnt],b[cnt]);
    for(int i=cnt-1;i>=1;i--) A2[i]=Search(10000-b[i])+b[i],Insert(10000-b[i],A2[i]);
    int ans=0;
    for(int i=2;i<=cnt;i++) A1[i]=max(A1[i],A1[i-1]);
    for(int i=cnt-1;i>=2;i--) A2[i]=max(A2[i],A2[i+1]);
    A2[cnt]=0;
    for(int i=1;i<=cnt;i++) ans=max(ans,A1[i]+A2[i+1]);
    ans=max(ans,A2[1]);
    return ans+10000;
}
inline void Array_Ini()
{
    memset(A1,0,sizeof(A1));
    memset(A2,0,sizeof(A2));
}
void Solve()
{
    while(scanf("%d",&n)!=EOF)
    {
        Array_Ini();
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i+n]=a[i];
        int ans=0;
        for(int i=1;i<=n;i++) if(a[i]==10000) ans=max(ans,Work(i));
        printf("%d\n",ans);
    }
}
int main()
{
    
    Solve();
    system("pause");
    return 0;
}