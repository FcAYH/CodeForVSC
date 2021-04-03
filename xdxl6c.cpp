#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=100010;
struct Monster{int hp,atk,step;}Mon[Maxn];
int t,n;
inline int Calc(int x)
{
    int sum=0,cnt=1;
    while(1)
    {
        sum++,x=x-cnt;
        if(x<=0) break;
        cnt++;
    }
    return sum;
}
inline int cmp(Monster a,Monster b){return a.step*b.atk<b.step*a.atk;}
void Solve()
{
    scanf("%d",&t);
    for(int CC=1;CC<=t;CC++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&Mon[i].hp,&Mon[i].atk);
            Mon[i].step=Calc(Mon[i].hp);
        }
        sort(Mon+1,Mon+1+n,cmp);
        ll sum=0,cnt=0;
        for(int i=1;i<=n;i++) cnt+=Mon[i].step,sum+=cnt*Mon[i].atk;
        printf("Case #%d: %lld\n",CC,sum);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}