#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int a,b;
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Solve()
{
    a=read(),b=read();
    printf("%d\n",a+b);
}
int main()
{
    Solve();
    //system("pause");
    return 0;
}
