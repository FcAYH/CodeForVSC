#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Solve()
{
    n=read(),m=read(),q=read();
    for(int i=1;i<=n;i++) city=read(),Cnt[city]++;
    int k;
    for(int i=1;i<=q;i++) 
    {
        k=read();

    }
}
int main()
{
    Solve();
    return 0;
}