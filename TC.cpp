#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int Maxn=100010;
int n,m;
int Blood[Maxn];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Solve()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++) Blood[i]=read();
    if(m==0) 
    {
        if(n%2) printf("odd\n");
        else printf("even\n"); 
    }
    else printf("even\n");
} 
int main()
{
    Solve();
    //system("pause");
    return 0;
}