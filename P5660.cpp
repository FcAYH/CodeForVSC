#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int cnt=0;
void Solve()
{
    for(int i=1;i<=8;i++) 
    {
        char ch=getchar();
        if(ch=='1') cnt++;
    }
    printf("%d\n",cnt);
}
int main()
{
    Solve();
    return 0;
}