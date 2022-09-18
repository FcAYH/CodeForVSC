#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n;
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Solve()
{
    T=read();
    while(T--)
    {
        n=read();
        if(n%2) printf("Bob\n");
        else printf("Alice\n");
    }
}
int main()
{
    Solve();
    //system("pause");
    return 0;
}