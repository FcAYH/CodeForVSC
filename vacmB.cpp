#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int Maxn=100000;
int n;
ll f[Maxn];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Solve()
{
    n=read();
    f[1]=1,f[2]=1,f[3]=1,f[4]=1;
    for(int i=5;i<=n+1;i++)
    {
        f[i]=f[i-1]+f[i-4];
    }
    printf("%lld\n",f[n+1]);
}
int main()
{
    Solve();
    //system("pause");
    return 0;
}
