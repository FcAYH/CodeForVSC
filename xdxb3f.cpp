#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,d,m,x,y;
void Solve()
{
    scanf("%d%d",&n,&d);
    scanf("%d",&m);
    for(int i=1;i<=m;i++) 
    {
        scanf("%d%d",&x,&y);
        if(x+y>=d&&x+y<=2*n-d&&x-y<=d&&x-y>=-d) printf("YES\n");
        else printf("NO\n");
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}