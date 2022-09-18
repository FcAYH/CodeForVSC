#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
int n,m;
void Solve()
{   
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&m);
        (m%2)?printf("zs wins\n"):printf("pb wins\n"); 
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}