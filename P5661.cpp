#include<cstdio>
#include<iostream>
#include<cstring>
#define debug(x) cout<<#x<<"="<<x<<endl;
using namespace std;
const int Maxn=1000000;
struct Subway{int t,p;}Stack[Maxn];
int vis[Maxn]; 
int n,si,pri,ti,ans=0,len=0;
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
    while(n--)
    {
        si=read(); pri=read(); ti=read();
        if(!si)
        {
            ans+=pri;
            Stack[++len].p=pri,Stack[len].t=ti;
        }
        else
        {
            int flag=0;
            for(int j=len;j;j--)
            {
                if(ti-Stack[j].t>45) break ;
                else if(Stack[j].p>=pri&&!vis[j]) flag=j;
            }
            if(flag) vis[flag]=1;
            else ans+=pri;
        }
    }
    printf("%d\n",ans);
}
int main()
{
    Solve();
    return 0;
}
/*
6
0 5 1
0 20 16
0 7 23
1 18 31
1 4 38
1 7 68 
*/