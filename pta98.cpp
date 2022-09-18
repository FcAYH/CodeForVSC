#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=10001;
int n;
struct Money{int num,v,id;}Mon[Maxn];
inline int cmp(Money a,Money b)
{
    if(a.v==b.v)
    {
        return (a.num==b.num)?a.id<b.id:a.num>b.num;
    }
    return a.v>b.v;
}
void Solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) Mon[i].id=i;
    int k,x,y;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k);
        int cnt=0;
        for(int j=1;j<=k;j++)
        {
            scanf("%d%d",&x,&y);
            Mon[x].v+=y; Mon[x].num++; cnt+=y;
        }
        Mon[i].v-=cnt;
    }
    sort(Mon+1,Mon+1+n,cmp);
    for(int i=1;i<=n;i++) printf("%d %.2lf\n",Mon[i].id,(double)Mon[i].v/100.0);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}