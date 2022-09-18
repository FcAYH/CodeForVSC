#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod=1000000007;
const int Maxn=1000010;
int t,n;
ll k;
ll a[Maxn],b[Maxn],p1[Maxn],p2[Maxn];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
ll p,q;
ll Exgcd(ll px,ll py)
{
    if(py==0){p=1ll,q=0ll; return px;}
    ll Gcd=Exgcd(py,px%py),t;
    t=p;p=q;q=t-(px/py)*q;
    return Gcd;
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
    t=read();
    while(t--)
    {
        n=read(); k=(ll)read();
        for(int i=1;i<=n;i++) a[i]=(ll)read(),b[i]=(ll)read();
        p1[n]=a[n],p2[n]=b[n];
        p1[n-1]=a[n]-k,p2[n-1]=b[n]+k;
        bool flag=0;
        for(int i=n-1;i>=1;i--)
        {
            p1[i]=max(p1[i],a[i]),p2[i]=min(p2[i],b[i]);
            if(p1[i]>p2[i]){flag=1; break ;}
            p1[i-1]=p1[i]-k,p2[i-1]=p2[i]+k;
        }
        if(flag) printf("NO\n");
        else
        {
            printf("YES\n");
            ll Temp=p1[1];
            printf("%lld ",Temp);
            for(int i=2;i<=n;i++)
            {
                if(Temp+k<=p2[i]) Temp+=k;
                else if(Temp-k>=p1[i]) Temp-=k;
                else Temp=p1[i];
                printf("%lld ",Temp);
            }
            puts("");
        }
    }

}
int main()
{
    Solve();
    system("pause");
    return 0;
}