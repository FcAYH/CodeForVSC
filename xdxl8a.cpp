#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int Maxn=100010;
const int Maxm=1000000;
int n,m,k,x;
int a[Maxn];
struct Seg_tree{int l,r,v;}T[Maxm];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Build_tree(int f,int ne,int poi)
{
    T[poi].l=f,T[poi].r=ne;
    if(f==ne) T[poi].v=a[f];
    else
    {
        int mid=(f+ne)>>1;
        Build_tree(f,mid,poi<<1);
        Build_tree(mid+1,ne,poi<<1|1);
        if(T[poi<<1].v==T[poi<<1|1].v) T[poi].v=T[poi<<1].v;
        else T[poi].v=0;
    }
}
inline void Insert(int go,int val,int poi)
{
    if(T[poi].l==go&&T[poi].r==go) T[poi].v=val;
    else
    {
        int mid=(T[poi].l+T[poi].r)>>1;
        if(go>mid) Insert(go,val,poi<<1|1);
        else Insert(go,val,poi<<1);
        if(T[poi<<1].v==T[poi<<1|1].v) T[poi].v=T[poi<<1].v;
        else T[poi].v=0;
    }
} 
void Solve()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    Build_tree(1,n,1);
    if(T[1].v!=0) printf("0");
    else
    {
        m=read();
        for(int i=1;i<=m;i++)
        {
            k=read(); x=read();
            Insert(k,x,1);
            if(T[1].v!=0) 
            {
                printf("%d",i);
                return ;
            }
        }
        printf("-1");
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}