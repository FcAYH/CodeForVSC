#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod=1000000007;
const int Maxn=1000010;
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
void Solve()
{
    string s;
    while(getline(cin,s))
    {
        cout<<"\""<<s<<"\","<<endl;
    }
}
int main()
{
    freopen("Makecppblock.in","r",stdin);
    freopen("Makecppblock.out","w",stdout);
    Solve();
    
    return 0;
}