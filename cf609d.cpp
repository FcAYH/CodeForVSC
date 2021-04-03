#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
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
    ll w=0ll,b=0ll;
    int n,a,si=1;
    n=read();
    for(int i=1;i<=n;i++) 
    {
        a=read();
        if(si)
        {
            if(a%2) w+=(ll)(a/2+1),b+=(ll)(a/2);
            else w+=(ll)(a/2),b+=(ll)(a/2);
        }
        else
        {
            if(!(a%2)) w+=(ll)(a/2),b+=(ll)(a/2);
            else w+=(ll)(a/2),b+=(ll)(a/2+1);
        }
        si^=1;
    }
    printf("%lld\n",min(w,b));
}
int main()
{
    Solve();
    system("pause");
    return 0;
}