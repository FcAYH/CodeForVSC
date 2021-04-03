#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=1000001;
const ll Mod=1000000007;
ll Ini[Maxn+1];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
inline ll Quick_Pow(ll a,ll b)
{
    ll ret=1;
    while(b>0)
    {
        if(b&1) ret*=a; a*=a,b>>=1; a%=Mod,ret%=Mod;
    }
    return ret;
}
void Ini_()
{
    for(int i=1;i<=Maxn-1;i++) Ini[i]=1;
    Ini[1]=0;
    for(int i=1;i<=Maxn-1;i++)
    {
        for(int j=2;i*j<=Maxn-1;j++)
        {
            Ini[i*j]=max(Ini[i*j],Ini[i]+1);
        }
    }
}
void Solve()
{
    Ini_();
    int t;
    t=read();
    while(t--)
    {
        ll n,c;
        n=read(); c=read();
        printf("%lld\n",Quick_Pow((ll)c,Ini[n]));
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}