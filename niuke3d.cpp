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
void Ini_()
{
    int cnt=1;
    MIN[1]=4,MAX[1]=4;
    MIN[2]=6,MAX[2]=8;
    for(int i=3;i<=50;i++)
    {
        MAX[i]=i*4;
        if(!(i%cnt)) MIN[i]=MIN[i-1]+2,cnt++;
    }
}
void Solve()
{
    Ini_();
    t=read();
    while(t--)
    {
        n=read(); m=read();

    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}