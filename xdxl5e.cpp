#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=10010;
int n;
int sum=0,ans1=-100,ans2=100;
int value[Maxn];
char name[Maxn][22];
inline int check(int x)
{
    int l=1,r=n-1;
    while(l<=r) 
    {
        int mid=(l+r)>>1;
        if((sum-(x*mid))/(n-mid)>=-50) 
        {
            if((sum-(x*mid))/(n-mid)*(n-mid)==sum-(x*mid)) ans1=max(ans1,x),ans2=min((sum-(x*mid))/(n-mid),ans2);
            l=mid+1;
        }
        else r=mid-1;
    }
    if(ans1==-100) return 0;
    return 1;
}
void Solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%s%d",(name[i]+1),&value[i]);
    for(int i=1;i<=n;i++) sum+=value[i]*100;
    sum=10000-sum;
    if(sum-49*(n-1)>=50){printf("IMPOSSIBLE"); return ;} 
    for(int i=49;i>=-50;i--) check(i);
    if(ans1==-100) printf("IMPOSSIBLE");
    else for(int i=1;i<=n;i++)
    {
        printf("%s %.2lf %.2lf\n",name[i]+1,((double)value[i]+(double)ans2/100.0),((double)value[i]+(double)ans1/100.0));
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
a 34
b 34
c 33
*/