#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int Maxn=4000;
int Ans[Maxn];
int A[Maxn];
int n,cnt=0;
inline int Check_illegal(int root,int left,int right,int tag)
{
    if(!tag)
    {
        for(int i=left;i<=right;i++) if(A[i]>=A[root]) return 1;
    }
    else
    {
        for(int i=left;i<=right;i++) if(A[i]<A[root]) return 1;
    }
    return 0;   
}
int Check_True()
{
    int flag=0;
    for(flag=2;flag<=n;flag++) if(A[flag]>=A[1]) break ;
    if(flag==2)  
    {
        if(Check_illegal(1,2,flag-1,1)||Check_illegal(1,flag,n,0)) printf("NO"),exit(0);
        return 0;
    }
    else
    {
        if(Check_illegal(1,2,flag-1,0)||Check_illegal(1,flag,n,1)) printf("NO"),exit(0);
        return 1;
    }
}
void Make_True(int root,int left,int right)
{
    if(left>right){if(root<=n) Ans[++cnt]=A[root]; return ;}
    int flag=0;
    for(flag=left;flag<=right;flag++) if(A[flag]>=A[root]) break ;

    if(Check_illegal(root,left,flag-1,0)) printf("NO"),exit(0);
    if(Check_illegal(root,flag,right,1)) printf("NO"),exit(0);

    if(flag==left) Make_True(flag,flag+1,right);
    else if(flag==right+1) Make_True(left,left+1,flag-1);
    else
    {
        Make_True(left,left+1,flag-1);
        Make_True(flag,flag+1,right);
    }
    Ans[++cnt]=A[root];
}
void Make_False(int root,int left,int right)
{
    if(left>right){if(root<=n) Ans[++cnt]=A[root]; return ;}
    int flag=0;
    for(flag=left;flag<=right;flag++) if(A[flag]<A[root]) break ;
    if(Check_illegal(root,left,flag-1,1))printf("NO"),exit(0);
    if(Check_illegal(root,flag,right,0))printf("NO"),exit(0);

    if(flag==left) Make_True(flag,flag+1,right);
    else if(flag==right+1) Make_True(left,left+1,flag-1);
    else
    {
        Make_True(left,left+1,flag-1);
        Make_True(flag,flag+1,right);
    }
    Ans[++cnt]=A[root];
}
void Solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&A[i]);
    if(Check_True()) Make_True(1,2,n);
    else Make_False(1,2,n);
    printf("YES\n");
    for(int i=1;i<n;i++) printf("%d ",Ans[i]);
    printf("%d",Ans[n]);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
7
8 6 5 7 10 8 11

9
5 4 3 2 1 6 7 8 9

true 0  3 
false  6

No 1 5

0 1 3 5 6
2 4 7

9
12 5 2 9 18 15 17 16 19

10
5 3 1 0 2 4 7 6 8 9

8
12 4 1 8 18 16 13 20

5
2 1 5 3 8
*/