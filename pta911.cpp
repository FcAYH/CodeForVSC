#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=10001;
int n,p;
char s1[Maxn],s2[Maxn];
int Mid[Maxn],First[Maxn];
int L[Maxn],R[Maxn];
int Q[Maxn];
int Depth[Maxn];
inline void Left(int,int,int);
inline void Right(int,int,int);
inline void Left(int l,int r,int poi)
{
    if(l>r) L[poi]=-1;
    else
    {
        p++;
        for(int i=l;i<=r;i++) if(Mid[i]==First[p])
        {
            L[poi]=First[p];
            int Root=First[p];
            Left(l,i-1,Root);
            Right(i+1,r,Root);
            return ;
        }
    }
}
inline void Right(int l,int r,int poi)
{
    if(l>r) R[poi]=-1; 
    else
    {
        p++;
        for(int i=l;i<=r;i++) if(Mid[i]==First[p])
        {
            R[poi]=First[p];
            int Root=First[p];
            Left(l,i-1,Root);
            Right(i+1,r,Root);
            return ;
        }
    }
}
void bfs(int poi)
{
    int head=1,tail=0,Maxd=1;
    Q[++tail]=poi;
    Depth[poi]=1;
    while(head<=tail)
    {
        int st=Q[head];
        Depth[L[st]]=Depth[R[st]]=Depth[st]+1;
        if(L[st]!=-1) Q[++tail]=L[st],Depth[L[st]]=Depth[st]+1,Maxd=max(Maxd,Depth[L[st]]);
        if(R[st]!=-1) Q[++tail]=R[st],Depth[R[st]]=Depth[st]+1,Maxd=max(Maxd,Depth[R[st]]);
        head++;
    }
    printf("%d",Maxd);
}
void Solve()
{
    scanf("%d",&n);
    cin>>(s1+1);
    cin>>(s2+1);
    for(int i=1;i<=n;i++) First[i]=s1[i]-'A';
    for(int i=1;i<=n;i++) Mid[i]=s2[i]-'A';
    int dc=0;
    for(int i=1;i<=n;i++) if(Mid[i]==First[1]) dc=i;
    p=1; 
    Left(1,dc-1,First[1]);
    Right(dc+1,n,First[1]);
    bfs(First[1]);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}

/*
9
ABDFGHIEC
FDHGIBEAC


*/