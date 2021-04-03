#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Solve()
{
    int t,n,a;
    t=read();
    while(t--)
    {
        n=read();
        ll ans=(ll)n;
        for(int i=1;i<=n;i++) a=read(),ans+=(ll)a;
        printf("%lld\n",ans);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}