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
    int t;
    t=read();
    while(t--)
    {
        int a,b,c,d;
        a=read(),b=read(),c=read(),d=read();
        if(a<b||d<c) printf("AB//CD\n"); 
        else printf("AB//DC\n");

    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}