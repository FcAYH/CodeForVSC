#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int N,a,b,ans=0;
void Solve()
{
    scanf("%d",&N);
    int iN=N;
    while(N) 
    {
        int is=N%10;
        ans+=is*is*is;
        N/=10;
    }
    if(ans==iN) printf("TRUE\n");
    else printf("FALSE\n");
}
int main()
{
    Solve();
    //system("pause");
    return 0;
}