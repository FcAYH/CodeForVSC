#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Solve()
{
    int t,A,B,C,D;
    t=read();
    while(t--)
    {
        A=read(),B=read(),C=read(),D=read();
        printf("%d %d\n%d %d\n",C,B+D,A,B+D);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}