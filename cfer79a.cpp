#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int t;
int a[10];
inline int cmp(int a,int b){return a<b;}
void Solve()
{
    scanf("%d",&t);
    while(t--)
    {
        for(int i=1;i<=3;i++) scanf("%d",&a[i]);
        sort(a+1,a+1+3,cmp);
        if(a[1]+a[2]+1>=a[3]) printf("Yes\n");
        else printf("No\n");
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}