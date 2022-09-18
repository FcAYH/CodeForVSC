#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
const int Maxn=100000;
int t,n;
ll Mod,x;
char ope[19];
ll Ope[Maxn];
struct Seg_Tree{int l,r; ll v;}T[Maxn*8];
inline void Build_Tree(int f,int ne,int poi)
{
    T[poi].l=f,T[poi].r=ne;
    if(f==ne) T[poi].v=1;
    else
    {
        int mid=(f+ne)>>1;
        Build_Tree(f,mid,poi<<1),Build_Tree(mid+1,ne,poi<<1|1);
        T[poi].v=T[poi<<1].v*T[poi<<1|1].v,T[poi].v%=Mod;
    }
}
inline void Insert(int go,ll val,int poi)
{
    if(T[poi].l==go&&T[poi].r==go) T[poi].v=val;     
    else
    {
        int mid=(T[poi].l+T[poi].r)>>1;
        if(go>mid) Insert(go,val,poi<<1|1);
        else Insert(go,val,poi<<1);
        T[poi].v=T[poi<<1].v*T[poi<<1|1].v,T[poi].v%=Mod;
    }
}
void Solve()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%lld",&n,&Mod);
        Build_Tree(1,Maxn,1);
        for(int i=1;i<=n;i++)
        {
            scanf("%s%lld",ope,&x);
            Ope[i]=x;
            if(ope[0]=='M') Insert(i,x,1);
            if(ope[0]=='D') Insert(x,1,1);
            printf("%lld\n",T[1].v);
        }
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}