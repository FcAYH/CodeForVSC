#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=200000;
int t,n,p;
ll a[Maxn];
int A[Maxn];
ll MOD[Maxn];
ll Pre[Maxn];
int Exist[Maxn];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Solve()
{
    t=read();
    while(t--)
    {
        memset(Exist,0,sizeof(Exist));
        n=read(), p=read();
        ll sum=0;
        for(int i=1;i<=n;i++) a[i]=read(),sum+=a[i],Pre[i]=sum;
        for(int i=1;i<=n;i++) MOD[i]=Pre[i]%p;
        A[0]=0;
        for(int i=1;i<=n;i++)
        {
            A[i]=A[i-1];
            if(Exist[MOD[i]]||!MOD[i]) A[i]=max(A[i],A[Exist[MOD[i]]]+1);
            Exist[MOD[i]]=i;
        }
        printf("%d\n",A[n]);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}