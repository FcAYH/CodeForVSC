#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=2000010;
ll n,ans=0ll;
ll f[Maxn];
ll F[Maxn];
inline void Array_Ini()
{
    ans=0ll;
    //memset(f,0,sizeof(f));
    memset(F,0,sizeof(F));
}
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Solve()
{
    while(n=read())
    {
        if(!n) break ;
        Array_Ini();
        for(int i=n;i>=1;i--)
        {
            F[i]=(ll)(n/i)*(ll)(n/i);
            for(int j=2;j*i<=n;j++) F[i]-=f[i*j];
            f[i]=F[i]; ans+=i*(f[i]/2ll);
        }
        printf("%lld\n",ans);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}