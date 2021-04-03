#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MaxT=120;
const int MaxM=10010;
int T,N,M;
int A[MaxT];
int f[MaxM];
int P[MaxT][MaxT];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Dynamic_P()
{
    for(int i=1;i<=T;i++) A[i]=M;
    for(int i=2;i<=T;i++)
    {
        memset(f,0,sizeof(f));
        for(int j=1;j<=N;j++)
        {
            for(int k=P[i-1][j];k<=A[i-1];k++) f[k]=max(f[k],f[k-P[i-1][j]]+(P[i][j]-P[i-1][j]));
        }
        A[i]=max(A[i],A[i-1]+f[A[i-1]]);
    }
    printf("%d\n",A[T]);
}
void Solve()
{
    T=read(),N=read(),M=read();
    for(int i=1;i<=T;i++)
    {
        for(int j=1;j<=N;j++) P[i][j]=read();
    }
    Dynamic_P();
}
int main()
{
    Solve();
    return 0;
}
/*
[3 1 100
10 
15 
15 ]
*/