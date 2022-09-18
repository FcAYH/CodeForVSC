#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Maxn=15;
const int Inf=0x3f3f3f3f;
int nowp=1,findx;
int mid[Maxn];
int fir[Maxn];
int Tree[Maxn<<2];
int si=0,Max=-Inf;
inline void Buildright(int l,int r,int fa);
inline void Buildleft(int l,int r,int fa)
{
    if(r<l) return ;
    nowp++;
    for(int i=l;i<=r;i++) if(mid[i]==fir[nowp])
    {
        Tree[fa<<1]=mid[i];
        Buildleft(l,i-1,fa<<1);
        Buildright(i+1,r,fa<<1);
    }
}
inline void Buildright(int l,int r,int fa)
{
    if(r<l) return ;
    nowp++;
    for(int i=l;i<=r;i++) if(mid[i]==fir[nowp])
    {
        Tree[fa<<1|1]=mid[i];
        Buildleft(l,i-1,fa<<1|1);
        Buildright(i+1,r,fa<<1|1);
    }
}
void MakeAns(int x,int poi)
{
    if(!Tree[poi]) return ; 
    if(Tree[poi]==x&&!si) si=1;
    if(si) Max=max(Max,Tree[poi]);
    MakeAns(x,poi<<1);
    if(Tree[poi]==x&&si) si=0;
    MakeAns(x,poi<<1|1);
}
void Solve()
{
    for(int i=1;i<=9;i++) cin>>fir[i];
    for(int i=1;i<=9;i++) cin>>mid[i];
    cin>>findx;
    Tree[1]=fir[1];
    for(int i=1;i<=9;i++) if(mid[i]==fir[1])
    {
        Buildleft(1,i-1,1);
        Buildright(i+1,9,1);
    }
    MakeAns(findx,1);
    cout<<Max<<endl;
}
int main()
{
    Solve();
    return 0;
}
/*
20 15 10 12 18 16 17 25 30
10 12 15 16 17 18 20 25 30
15
*/