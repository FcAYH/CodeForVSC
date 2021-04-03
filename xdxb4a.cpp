#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Maxn=4000;
int t;
ll ans=0,n;
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Solve()
{
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%lld",&n);
        ans=0ll;
        ll j=0ll;
        for(int i=1;i<=n;i=j+1)
        {
            j=n/(n/(ll)i); 
            ans+=n/(ll)i*(j-(ll)i+1);
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