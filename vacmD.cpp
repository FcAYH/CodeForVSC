#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int a,b;
void Solve()
{
    scanf("%d%d",&a,&b);
    while(a!=0&&b!=0)
    {
        printf("%d\n",a+b);
        scanf("%d%d",&a,&b);
    }
    //while(scanf("%d%d",&a,&b)!=EOF) printf("%d\n",a+b);
}
int main()
{
    Solve();
    //system("pause");
    return 0;
}