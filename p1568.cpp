#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=2000010;
int n,m;
int v1[Maxn],v2[Maxn];
int t1[Maxn],t2[Maxn];
int X1[Maxn],X2[Maxn];
void Solve()
{
    //freopen("P1568_1.in","r",stdin);
    //freopen("P1568_1.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d%d",&v1[i],&t1[i]);
    for(int i=1;i<=m;i++) scanf("%d%d",&v2[i],&t2[i]);
    int sum=0,Mint=0;
    for(int i=1;i<=n;i++) sum+=t1[i];
    Mint=sum;
    int flag=0,cnt=0,C1=1,C2=1;
    for(int i=1;i<=n;i++) t1[i]+=t1[i-1];
    for(int i=1;i<=m;i++) t2[i]+=t2[i-1];
    for(int i=1;i<=Mint;i++)
    {
        if(t1[C1]<i) C1++;
        if(t2[C2]<i) C2++;
        X1[i]=X1[i-1]+v1[C1];
        X2[i]=X2[i-1]+v2[C2];
        if(i==1) continue ;
        //printf("%d ",X1[i]);
        if(X1[i]>X2[i]&&X1[i-1]<=X2[i-1]) cnt++;
        if(X1[i]<X2[i]&&X1[i-1]>=X2[i-1]) cnt++; 
    }
    printf("%d",cnt);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
4 3
1 2
4 1
1 1
2 10
2 3
1 2
3 9

1 2 6 7 9 11 13 15 17 19 21 23 25 27 

2 4 6 7 8 11 ...
*/