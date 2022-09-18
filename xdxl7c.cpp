#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;
int n;
bool vis[1010];
struct pro{int t,a;}s[1010];
bool cmp(pro p1, pro p2)
{
    return (p1.t==p2.t)?p1.a>p2.a:p1.t>p2.t;
}
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Solve()
{
    int T;
    T=read();
    while(T--)
    {
        int ans=0,tot=0;
        n=read();
        for(int i=1;i<=n;i++) s[i].t=read(),vis[i]=0;;
        for(int i=1;i<=n;i++) s[i].a=read(),tot+=s[i].a;
        sort(s+1,s+1+n,cmp);
        for(int i=1;i<=n;i++)
        {
            if(s[i].t<1) break;
            int Max=0,pos=0;
            for(int j=i;j<=n;j++)
            {
                if(s[j].t!=s[i].t) break;
                else if(s[j].a>Max) Max=s[j].a,pos=j;
            }
            swap(s[i],s[pos]);
            for(int j=i+1;j<=n;j++)
            {
                if(s[j].t!=s[i].t) break;
                else s[j].t--;
            }
            ans+=s[i].a;
        }
        printf("%d\n",tot-ans);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
3
3
3 3 3
10 5 1
3 
1 3 1
6 2 3
7
1 4 6 4 2 4 3
3 2 1 7 6 5 4
*/
