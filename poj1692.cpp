#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Maxn=300;
int M,n1,n2;
int s1[Maxn];
int s2[Maxn];
int f[Maxn][Maxn];
int g[Maxn][Maxn];
int A[Maxn][Maxn];
void Ini_()
{
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++) f[i][j]=(s2[j-1]==s1[i])?j-1:f[i][j-1];
    }
    for(int i=1;i<=n2;i++)
    {
        for(int j=1;j<=n1;j++) g[i][j]=(s1[j-1]==s2[i])?j-1:g[i][j-1];
    }    
}
void Dynamic_P()
{
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            A[i][j]=max(A[i-1][j],A[i][j-1]);
            /*int ii=0,jj=0;
            for(ii=i-1;ii>=1;ii--) if(s1[ii]==s2[j]) break ;
            for(jj=j-1;jj>=1;jj--) if(s2[jj]==s1[i]) break ;
            if(ii&&jj&&(s1[i]!=s2[j])) A[i][j]=max(A[i][j],A[ii-1][jj-1]+2);
            //printf("<%d %d> %d %d %d %d\n",i,j,g[j],ii,f[i],jj);
            */
            if((s1[i]!=s2[j])&&f[i][j]&&g[j][i]) A[i][j]=max(A[i][j],A[g[j][i]-1][f[i][j]-1]+2);
        }
    }
}
inline void Array_Ini()
{
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    memset(A,0,sizeof(A));
}
void Solve()
{
    scanf("%d",&M);
    while(M--)
    {
        Array_Ini();
        scanf("%d%d",&n1,&n2);
        for(int i=1;i<=n1;i++) scanf("%d",&s1[i]);
        for(int i=1;i<=n2;i++) scanf("%d",&s2[i]);
        Ini_();
        Dynamic_P();
        printf("%d\n",A[n1][n2]);
    }
}
int main()
{
    Solve();//2019113035
    system("pause");
    return 0;
}