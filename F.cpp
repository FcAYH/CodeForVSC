#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Maxn=6000;
int T,n;
int A[Maxn];
double hight[Maxn];
inline void Longest_Down()
{
    A[1]=1;
    for(int i=2;i<=n;i++)
    {
        A[i]=1;
        for(int j=i-1;j>=1;j--)
        {
            if(hight[j]>=hight[i]) A[i]=max(A[i],A[j]+1);
        }
    }
}
void Solve()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(A,0,sizeof(A));
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lf",&hight[i]);
        Longest_Down();
        int MAXD=-1;
        for(int i=1;i<=n;i++) MAXD=max(MAXD,A[i]);
        printf("%d\n",n-MAXD);
    }
}
int main()
{
    Solve();
    //system("pause");
    return 0;
}

//164.1 180.15 165.2 195 175.5
//175 175 175 156 175 175 176 160 156 156
//176 175 175 175 175 175 160 156 156 156
/*
10000
10
123 3325 45 244 6436 754 33 25 7345 7
10 
4.5 9.87 1.22 0.2 99 8.7 1.2 33.33 11.1 10
*/