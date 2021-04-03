#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int Maxn=2005;
int N;
double V,X;
double A[Maxn][Maxn][3];
struct Elephant
{
    double x,spe;
}Ele[Maxn];
inline int cmp(Elephant a,Elephant b){return a.x<b.x;}
void Dynamic_P()
{
    for(int i=1;i<=N;i++) A[i][i][1]=(abs(X-Ele[i].x)/V)*Ele[i].spe,A[i][i][2]=A[i][i][1];
    //printf("%lf %lf\n",A[2][2][1],A[2][2][2]);
    for(int i=2;i<=N;i++)
    {
        for(int l=1;l<=N-i+1;l++)
        {
            int r=l+i-1;
            double Ans1=(A[l+1][r][1]+(Ele[l+1].x-Ele[l].x)/V)*Ele[l].spe+A[l+1][r][1];
            double Ans2=(A[l+1][r][2]+(Ele[r].x-Ele[l].x)/V)*Ele[l].spe+A[l+1][r][2];
            double Ans3=(A[l][r-1][1]+(Ele[r].x-Ele[l].x)/V)*Ele[r].spe+A[l][r-1][1]+(Ele[r].x-Ele[l].x)/V;
            double Ans4=(A[l][r-1][2]+(Ele[r].x-Ele[r-1].x)/V)*Ele[r].spe+A[l][r-1][2]+(Ele[r].x-Ele[l].x)/V;
            A[l][r][1]=min(Ans1,min(Ans2,min(Ans3,Ans4)));
            double Ans5=Ans1+(Ele[r].x-Ele[l].x)/V;
            double Ans6=Ans2+(Ele[r].x-Ele[l].x)/V;
            double Ans7=Ans3-(Ele[r].x-Ele[l].x)/V;
            double Ans8=Ans4-(Ele[r].x-Ele[l].x)/V;
            A[l][r][2]=min(Ans5,min(Ans6,min(Ans7,Ans8)));
        }
    }
}
void Solve()
{
    while(scanf("%d%lf%lf",&N,&V,&X)!=EOF)
    {
        for(int i=1;i<=N;i++) scanf("%lf%lf",&Ele[i].x,&Ele[i].spe);
        sort(Ele+1,Ele+1+N,cmp); 
        Dynamic_P();   
        printf("%.0lf\n",min(A[1][N][1],A[1][N][2]));
    }
}
int main()
{
    Solve();
    return 0;
}