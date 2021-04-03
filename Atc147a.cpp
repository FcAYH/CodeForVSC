#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
void Solve()
{
    int a1,a2,a3;
    scanf("%d%d%d",&a1,&a2,&a3);
    if(a1+a2+a3>=22) printf("bust");
    else printf("win");
}
int main()
{
    Solve();
    return 0;
}