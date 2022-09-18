#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=1001;
int p=0,cnt=0;
int n;
int Mid[Maxn];
int Back[Maxn];
int L[Maxn];
int R[Maxn];
int Q[Maxn];
int Ans[Maxn];
inline void Left(int,int,int);
inline void Right(int,int,int);
inline void Right(int l,int r,int poi)
{
    if(l>r) R[poi]=-1; 
    else
    {
        p--;
        for(int i=l;i<=r;i++) if(Mid[i]==Back[p])
        {
            R[poi]=Back[p];
            int Root=Back[p];
            Right(i+1,r,Root);
            Left(l,i-1,Root);
            return ;
        }
    }
}
inline void Left(int l,int r,int poi)
{
    if(l>r) L[poi]=-1;
    else
    {
        p--;
        for(int i=l;i<=r;i++) if(Mid[i]==Back[p])
        {
            L[poi]=Back[p];
            int Root=Back[p];
            Right(i+1,r,Root);
            Left(l,i-1,Root);
            return ;
        }
    }
}
void bfs(int poi)
{
    int head=1,tail=0;
    Q[++tail]=poi;
    while(head<=tail)
    {
        Ans[++cnt]=Q[head];
        int st=Q[head];
        if(L[st]!=-1) Q[++tail]=L[st];
        if(R[st]!=-1) Q[++tail]=R[st];
        head++;
    }
    for(int i=1;i<cnt;i++) printf("%d ",Ans[i]);
    printf("%d",Ans[cnt]);
}
void Solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&Back[i]);
    for(int i=1;i<=n;i++) scanf("%d",&Mid[i]);
    int dc=0;
    for(int i=1;i<=n;i++) if(Mid[i]==Back[n]) dc=i;
    p=n;
    Right(dc+1,n,Back[n]);
    Left(1,dc-1,Back[n]);
    bfs(Back[n]);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7


123  4  5 6 7

    4

*/