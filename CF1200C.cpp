#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,q;
ll sx,sy,ex,ey;
inline ll read()
{
    ll fl=1ll,rt=0ll; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1ll; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10ll+ch-'0'; ch=getchar();}
    return fl*rt;
}
inline ll gcd(ll x,ll y)
{
    return (!y)?x:gcd(y,x%y);
}
void Solve()
{
    n=read(),m=read(),q=read();
    ll G1=n/gcd(n,m),G2=m/gcd(n,m);
    for(int i=1;i<=q;i++)
    {
        sx=read(),sy=read(),ex=read(),ey=read();
        if(sx==1&&ex==1)
        {
            if(sy>ey) swap(sy,ey);
            ll  k1=(sy-1)/G1,k2=(ey-1)/G1;
            if(k1==k2) printf("YES\n");
            else printf("NO\n");
        }
        else if(sx==2&&ex==2)
        {
            if(sy>ey) swap(sy,ey);
            ll  k1=(sy-1)/G2,k2=(ey-1)/G2;
            if(k1==k2) printf("YES\n");
            else printf("NO\n");
        }
        else 
        {
            if(sx==2) swap(sx,ex),swap(sy,ey);
            ll k1=(sy-1)/G1,k2=(ey-1)/G2;
            if(k1==k2) printf("YES\n");
            else printf("NO\n");
        }
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
2 3 5
2 3 1 2
2 3 2 3
1 1 1 1
1 2 1 2
2 1 2 1
*/