#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int Q,n;
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
inline int Check(int x)
{
    for(int i=2;i<=sqrt(x);i++) if(!(x%i)) return 0;
    return 1;
}
void Solve()
{
    Q=read();
    while(Q--)
    {
        n=read();
        if(Check(n)) printf("Yes\n");
        else printf("No\n");
    }    
}
int main()
{
    Solve();
    //system("pause");
    return 0;
}
/*
10
123123124
124214134
313432532
235245432
134325324
134314323
314124214
546757576
857687679
568748757
*/