#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=3000;
double Rel[Maxn][Maxn];
int n,m;
int A,B,iA,iB;
int Id[Maxn];
int k[Maxn];
int pic[Maxn][Maxn];
int tag;
inline int read()
{
    tag=0;
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    if(fl==-1) tag=1;
    return fl*rt;
}
void Calc()
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=k[i];j++)
        {
            if(pic[i][j]==iA||pic[i][j]==iB)
                for(int l=1;l<=k[i];l++) if(j!=l) Rel[pic[i][j]][pic[i][l]]+=1.0/(double)k[i];
        }
    }
}
void Make_set()
{
    for(int i=0;i<=999;i++) Id[i]=i-999;
    for(int i=1000;i<=1999;i++) Id[i]=i-1000;
}
void Solve()
{
    Make_set();
    n=read(),m=read();   
    for(int i=1;i<=m;i++)
    {
        k[i]=read();
        for(int j=1;j<=k[i];j++) 
        {
            int x=read();
            tag?pic[i][j]=x+999:pic[i][j]=x+1000;
        }
    }
    A=read(); (tag)?iA=A+999:iA=A+1000;
    B=read(); (tag)?iB=B+999:iB=B+1000;
    Calc();
    double Max1=-1.0,Max2=-1.0;
    if(iA<=999) for(int i=1000;i<=1999;i++) Max1=max(Max1,Rel[iA][i]);
    else for(int i=0;i<=999;i++) Max1=max(Max1,Rel[iA][i]);
    if(iB<=999) for(int i=1000;i<=1999;i++) Max2=max(Max2,Rel[iB][i]);
    else for(int i=0;i<=999;i++) Max2=max(Max2,Rel[iB][i]);
    if(Rel[iA][iB]==Max1&&Rel[iB][iA]==Max2)
    {
        if(iA==999&&iB!=999) printf("-0 %d",Id[iB]);
        else if(iA!=999&&iB==999) printf("%d -0",Id[iA]);
        else printf("%d %d",Id[iA],Id[iB]); return ;
    }
    else
    {
        if(iA==999)
        {
            for(int i=1000;i<=1999;i++) if(Rel[iA][i]==Max1) printf("-0 %d\n",Id[i]);
        }
        else if(iA<999) for(int i=1000;i<=1999;i++)
        {
            if(Rel[iA][i]==Max1) printf("%d %d\n",Id[iA],Id[i]);
        }
        else for(int i=999;i>=0;i--)
        {
            if(Rel[iA][i]==Max1&&i==999) printf("%d -0\n",Id[iA]);
            else if(Rel[iA][i]==Max1) printf("%d %d\n",Id[iA],Id[i]);
        }
        if(iB==999) 
        {
            for(int i=1000;i<=1999;i++) if(Rel[iB][i]==Max2) printf("-0 %d\n",Id[i]);
        }
        else if(iB<999) for(int i=1000;i<=1999;i++)
        {
            if(Rel[iB][i]==Max2) printf("%d %d\n",Id[iB],Id[i]);
        }
        else for(int i=999;i>=0;i--)
        {
            if(Rel[iB][i]==Max2&&i==999) printf("%d -0\n",Id[iB]);
            else if(Rel[iB][i]==Max2) printf("%d %d\n",Id[iB],Id[i]);
        }
    }  
}
int main()
{
    Solve();
    system("pause");
    return 0;
}