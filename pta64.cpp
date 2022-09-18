#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int Maxn=200;
int Ra,Rb,Ca,Cb;
int Matrix1[Maxn][Maxn];
int Matrix2[Maxn][Maxn];
int Matrix3[Maxn][Maxn];
int main()
{
    scanf("%d%d",&Ra,&Ca);
    for(int i=1;i<=Ra;i++)
    {
        for(int j=1;j<=Ca;j++) scanf("%d",&Matrix1[i][j]);
    }
    scanf("%d%d",&Rb,&Cb);
    for(int i=1;i<=Rb;i++)
    {
        for(int j=1;j<=Cb;j++) scanf("%d",&Matrix2[i][j]);
    }
    if(Ca!=Rb) 
    {
        printf("Error: %d != %d",Ca,Rb); return 0;
    }
    else
    {
        for(int i=1;i<=Ra;i++)
        {
            for(int j=1;j<=Cb;j++)
            {
                for(int k=1;k<=Ca;k++) Matrix3[i][j]=(Matrix3[i][j]+Matrix1[i][k]*Matrix2[k][j]);
            }
        }
        printf("%d %d\n",Ra,Cb);
        for(int i=1;i<=Ra;i++)
        {
            for(int j=1;j<Cb;j++) printf("%d ",Matrix3[i][j]);
            printf("%d\n",Matrix3[i][Cb]);
        }
    }
    system("pause");
    return 0;
}