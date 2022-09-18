#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define LL long long
#define LD long double
using namespace std;
const int MAXN=1e5+10;
int n,a[MAXN<<1],MX[MAXN<<1][19],MN[MAXN<<1][19],ans[MAXN],MXX,MNN=1e9;
int read(){int sss=0,fff=1;char ccc;ccc=getchar();while(ccc<'0'||ccc>'9'){if(ccc=='-')fff=-1;ccc=getchar();}while(ccc>='0'&&ccc<='9')sss=(sss<<1)+(sss<<3)+(ccc^'0'),ccc=getchar();return sss*fff;}
int MinST(int l,int r)
{
    int len=r-l+1;
    int k=log2(len);
    if(a[MN[l][k]]<a[MN[r-(1<<k)+1][k]]) return MN[l][k];
    return MN[r-(1<<k)+1][k];
}
int MaxST(int l,int r)
{
    int len=r-l+1;
    int k=log2(len);
    if(a[MX[l][k]]>a[MX[r-(1<<k)+1][k]]) return MX[l][k];
    return MX[r-(1<<k)+1][k];
}
int Min(int l,int r)
{
    int x=a[l-1];
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(a[MinST(l,mid)]*2>=x) l=mid+1;
        else r=mid;
    }
    return l;
}
int Max(int l,int r)
{
    int x=a[l-1];
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(a[MaxST(l,mid)]<x) l=mid+1;
        else r=mid;
    }
    return l;
}
int solve(int x)
{
    if(ans[x]) return ans[x];
    int A=Min(x+1,x+n),B=Max(x+1,x+n);
    if(A<B) return ans[x]=A-x;
    else return ans[x]=B-x+solve((B-1)%n+1);
}
int main()
{
//  freopen("123.in","r",stdin);
//  freopen("123.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++) a[i]=a[i+n]=read(),MX[i][0]=MN[i][0]=i,MX[i+n][0]=MN[i+n][0]=i+n,MXX=max(MXX,a[i]),MNN=min(MNN,a[i]);
    if(MNN*2>=MXX)
    {
        for(int j=1;j<=n;j++)
            printf("-1 ");
        return 0;
    }
    for(int k=1;k<=18;k++)
    {
        int len=1<<k;
        for(int i=1;i+len-1<=n*2;i++)
        {
            int j=i+len-1,mid=i+(len/2);

            if(a[MX[i][k-1]]<a[MX[mid][k-1]]) MX[i][k]=MX[mid][k-1];
            else MX[i][k]=MX[i][k-1];

            if(a[MN[i][k-1]]>a[MN[mid][k-1]]) MN[i][k]=MN[mid][k-1];
            else MN[i][k]=MN[i][k-1];
        }
    }
    for(int i=1;i<=n;i++)
        ans[i]=solve(i);
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    system("pause");
    return 0;
}
/*
6
6 5  11 8 6 7 
6 5 11 8 6 7 6 5 11 8 6 7
*/