#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod=1000000007;
const int Maxn=20000010;
int t,n;
ll Inv[Maxn];
ll f[Maxn];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Ini_()
{
    Inv[0]=1ll;
    Inv[1]=500000004ll;
	for(register int i=2;i<=20000000;i++) Inv[i]=(Inv[i-1]*Inv[1])%Mod;
    f[0]=1;
    ll POW=2ll;
    for(register int i=1;i<=20000000;i++) 
    {
        f[i]=(((POW-1)*f[i-1])%Mod*Inv[i])%Mod;
        POW<<=1; POW%=Mod;
    }
    for(register int i=2;i<=20000000;i++) f[i]=f[i]^f[i-1],f[i]%=Mod; 
}
void Solve()
{
    Ini_();
    t=read();
    while(t--)
    {
        n=read();
        cout<<f[n]<<endl;
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}