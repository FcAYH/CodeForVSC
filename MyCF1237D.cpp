#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Maxn=100100;
const int Inf=0x3f3f3f3f;
int n;
int sl[Maxn<<1];
int A[Maxn<<1];
struct SegTree{int l,r,Maxv,Minv;}T[1001000];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Buildtree(int f,int ne,int poi)
{
    T[poi].l=f,T[poi].r=ne;
    if(f==ne)
    {
        T[poi].Maxv=T[poi].Minv=sl[f]; return ;
    }
    int mid=(f+ne)>>1;
    Buildtree(f,mid,poi<<1),Buildtree(mid+1,ne,poi<<1|1);
    T[poi].Maxv=max(T[poi<<1].Maxv,T[poi<<1|1].Maxv);
    T[poi].Minv=min(T[poi<<1].Minv,T[poi<<1|1].Minv);
}
inline int SearchMax(int f,int ne,int poi)
{
    if(f>ne) return 0;
    if(T[poi].l==f&&T[poi].r==ne) return T[poi].Maxv;
    int mid=(T[poi].l+T[poi].r)>>1;
    if(f>mid) return SearchMax(f,ne,poi<<1|1);
    else if(ne<=mid) return SearchMax(f,ne,poi<<1);
    else return max(SearchMax(f,mid,poi<<1),SearchMax(mid+1,ne,poi<<1|1));
}
inline int SearchMin(int f,int ne,int poi)
{
    if(f>ne) return Inf;
    if(T[poi].l==f&&T[poi].r==ne) return T[poi].Minv;
    int mid=(T[poi].l+T[poi].r)>>1;
    if(f>mid) return SearchMin(f,ne,poi<<1|1);
    else if(ne<=mid) return SearchMin(f,ne,poi<<1);
    else return min(SearchMin(f,mid,poi<<1),SearchMin(mid+1,ne,poi<<1|1));
}
int BinarysearchMax(int l,int r)
{
    if(SearchMax(l,r,1)<=sl[l-1]) return r+1;
    int AiM=sl[l-1];
    while(l<=r)
    {
        int mid=(l+r)>>1;
        int Max1=SearchMax(l,mid-1,1),Max2=SearchMax(mid,mid,1),Max3=SearchMax(mid+1,r,1);
        if(Max2>AiM&&Max1<=AiM) return mid;
        if(Max1>AiM) r=mid-1; else l=mid+1;
    }
    return r+1;
}
int BinarysearchMin(int l,int r)
{
    if(SearchMin(l,r,1)*2>sl[l-1]) return r+1;
    int AiM=sl[l-1];
    while(l<=r)
    {
        int mid=(l+r)>>1;
        int Min1=SearchMin(l,mid-1,1),Min2=SearchMin(mid,mid,1),Min3=SearchMin(mid+1,r,1);
        if(Min2*2<AiM&&Min1*2>=AiM) return mid;
        if(Min1*2<AiM) r=mid-1; else l=mid+1;
    }
    return r+1;
}
inline int Work(int x)
{
    if(A[x]) return A[x];
    int firMax=BinarysearchMax(x+1,x+n);
    //printf("< %d >",firMax);
    int firMin=BinarysearchMin(x+1,x+n);
    if(firMin<firMax) return A[x]=firMin-x;
    else return A[x]=firMax-x+Work((firMax-1)%n+1);
}
int Check()
{
    int Max=-1,Min=1e9+7;
    for(int i=1;i<=n;i++) Max=max(Max,sl[i]),Min=min(Min,sl[i]);
    if(Max<=Min*2) return 1;
    return 0;
}
void Solve()
{
    n=read();
    for(int i=1;i<=n;i++) sl[i]=read(),sl[i+n]=sl[i];
    if(Check())
    {
        for(int i=1;i<=n;i++) printf("-1 "); puts(""); return ;
    }
    Buildtree(1,n+n,1);
    for(int i=1;i<=n;i++) A[i]=Work(i);
    for(int i=1;i<=n;i++) printf("%d ",A[i]);
    puts("");
}
int main()
{
    freopen("CF1237.in","r",stdin);
    freopen("CF1237.out","w",stdout);
    Solve();
    system("pause");
    return 0;
}
/*
4
11 5 2 7

11 5 2 7 11 5 2 7
 1 2 3 4  5 6 7 8


10
1 1 1 1 1 1 1 1 1 0
*/