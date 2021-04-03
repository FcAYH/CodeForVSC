#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll a,b;
ll p,q;
inline ll read()
{
    ll fl=1ll,rt=0ll; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1ll; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10ll+ch-'0'; ch=getchar();}
    return fl*rt;
}
inline ll gcd(ll a,ll b){return (!b)?a:gcd(b,a%b);}

inline ll Exgcd(int x,int y)
{
	if(y==0)
	{
		p=1; q=0;
		return x;
	}
	int Gcd=Exgcd(y,x%y);
	int t;
	t=p; p=q; q=t-(x/y)*q;
	return Gcd;
}

inline int Work(ll x,ll y)
{
    ll G=Exgcd(x,y);
    p=-p;
    if(!(p%G)&&!(q%G))
    {
        p=p/G*a,q=q/G*a;
        printf("%lld %lld %lld %lld\n",p,x,q,y);
        return 1;
    }
}

void Solve()
{
    t=read();
    while(t--)
    {
        a=read(),b=read();
        ll G=gcd(a,b);
        ll ib=b;
        a/=G,b/=G;
        int flag=1;
        while(b<=ib)
        {
            for(ll i=2;i<=sqrt(b);i++)
            {
                if(!(b%i)) if(Work(i,b/i)){flag=0; break ;}
            }
            b+=b;a+=a;
            if(!flag) break ;
        }
        if(flag) printf("-1 -1 -1 -1\n");
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
