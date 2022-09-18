#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MaxT=800000;
const int Maxn=201000;
int n;
int Pos[Maxn];
ll T1[MaxT+10];
ll T2[MaxT+10];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
inline void Insert(ll *T,int x,ll y)
{
    while(x<=MaxT) T[x]+=y,x+=x&(-x);
}
inline ll Search(ll *T,int x)
{
    ll ret=0;
    while(x>0) ret+=T[x],x-=x&(-x);
    return ret;
}
void Solve()
{
    n=read();
    int a;
    for(int i=1;i<=n;i++) a=read(),Pos[a]=i;
    ll ans1=0ll,ans2=0ll;
    for(int i=1;i<=n;i++)
    {
        ans1+=i-1-Search(T1,Pos[i]);
        Insert(T1,Pos[i],1ll);
        Insert(T2,Pos[i],(ll)Pos[i]);
        int l=1,r=n,mid=(l+r)>>1;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if((Search(T1,mid)<<1)<=i) l=mid+1;
            else r=mid-1;
        }
        ans2=0;
        ll cnt=(ll)Search(T1,mid),sum=(ll)Search(T2,mid);
        ans2+=mid*cnt-sum-cnt*(cnt-1ll)/2ll;
        cnt=i-cnt,sum=Search(T2,n)-sum;
        ans2+=sum-cnt*(ll)(mid+1ll)-cnt*(cnt-1ll)/2ll;
        printf("%lld ",ans1+ans2);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
} 

/*
10
5 1 6 2 8 3 4 10 9 7

0 1 3 5
*/