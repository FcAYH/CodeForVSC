#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int Maxn=30;
int n;
int a[Maxn];
void Solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int cntf=0,cntb=0;
    for(int i=1;i<=n;i++) if(!a[i]){cntf=i; break ;}
    for(int i=n;i>=1;i--) if(!a[i]){cntb=n-i+1; break ;}
    if(!cntf&&!cntb) (!(n%2))?printf("NO\n"):printf("YES\n");
    else
    {
        if(!(cntf%2)) printf("YES\n");
        else if(!(cntb%2)) printf("YES\n");
        else printf("NO\n");
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}