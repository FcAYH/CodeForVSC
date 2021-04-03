#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Maxn=303003;
ll n,ans1=0ll,Ans=0ll,ans3=0ll;
ll s[3][Maxn];
ll Pre[5][Maxn];
ll Ip[3][Maxn];


void Solve()
{
    scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&s[1][i]);
	for(int i=1;i<=n;i++) scanf("%lld",&s[2][i]);
    
    for(int i=1;i<=n;i++) Ip[1][i]=Ip[1][i-1]+s[1][i];
    for(int i=1;i<=n;i++) Ip[2][i]=Ip[2][i-1]+s[2][i];

    for(int i=1;i<=n;i++) Pre[1][i]=Pre[1][i-1]+(ll)(i-1)*s[1][i];
    for(int i=1;i<=n;i++) Pre[2][i]=Pre[2][i-1]+(ll)(2*n-i)*s[2][i];

    for(int i=1;i<=n;i++) Pre[3][i]=Pre[3][i-1]+(ll)(i)*s[2][i];
    for(int i=2;i<=n;i++) Pre[4][i]=Pre[4][i-1]+(ll)(2*n-i+1)*s[1][i];

    for(ll i=1ll;i<=n;i++) ans1+=s[1][i]*(i-1ll);
	for(ll i=n;i>=1ll;i--) ans1+=s[2][i]*(2ll*n-i);

    ll tAns=0ll,cj=2ll;
    for(int i=2;i<=n;i+=2)
    {
        tAns+=s[1][i-1]*(ll)(2*i-4)+s[2][i-1]*(ll)(2*i-3)+s[2][i]*(ll)(2*i-2)+s[1][i]*(ll)(2*i-1);
        ll Temp=Pre[1][n]-Pre[1][i]+Pre[2][n]-Pre[2][i];
        Temp+=cj*(Ip[1][n]-Ip[1][i]);
        Temp+=cj*(Ip[2][n]-Ip[2][i]); cj<<=1;
        //if(i==2) printf("%lld %lld\n",tAns,Temp);
        Ans=max(Ans,tAns+Temp);
    }

    tAns=0ll,cj=2ll;
    tAns+=s[2][1];

    for(int i=3;i<=n;i+=2)
    {
        tAns+=s[2][i-1]*(ll)(2*i-4)+s[1][i-1]*(ll)(2*i-3)+s[1][i]*(ll)(2*i-2)+s[2][i]*(ll)(2*i-1);
        ll Temp=Pre[1][n]-Pre[1][i]+Pre[2][n]-Pre[2][i];;
        Temp+=cj*(Ip[1][n]-Ip[1][i]);
        Temp+=cj*(Ip[2][n]-Ip[2][i]); cj<<=1;
        Ans=max(Ans,tAns+Temp);
    }

    for(int i=1;i<=n;i++) ans3+=(ll)i*s[2][i];
    for(int i=n;i>=2;i--) ans3+=(ll)(2*n-i+1)*s[1][i];
    //printf("%lld %lld %lld %lld",ans1,ans2,ans3,ans4);
    //printf("%lld %lld %lld ",Ans,ans1,ans3);
	printf("%lld",max(Ans,max(ans1,ans3)));
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
3

1 6 5
2 3 4

3
1 2 3
6 5 4

5
1 4 5 6 7
2 3 10 9 8
*/