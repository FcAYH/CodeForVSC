#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int T,Ip1,Ip2,Ip3,Ip4,n;
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
inline int Change(int x)
{
    int ret=1;
    while(x/2) ret++,x/=2;
    return ret;
}
inline int Calc(int x)
{
    int POW2=2*2*2*2*2*2*2,ret=0;
    for(int i=1;i<=x;i++) ret+=POW2,POW2/=2;
    return ret;
}
void Solve()
{
    T=read();
    while(T--)
    {
        scanf("%d.%d.%d.%d",&Ip1,&Ip2,&Ip3,&Ip4); scanf("%d",&n);
        int length=Change(n);
        //printf("<%d> ",length);
        printf("255.255.255.%d\n",Calc(length));
    }
}
int main()
{
    Solve();
    //system("puase");
    return 0;
}