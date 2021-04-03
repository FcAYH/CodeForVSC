#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MaxL=300000;
int n,x,y;
char s[MaxL];
void Solve()
{
    cin>>n>>x>>y;
    cin>>(s+1);
    int nowp=0;
    int cnt=0;
    while(nowp<x) 
    {
        if(s[n-nowp]=='1'&&nowp!=y) cnt++;
        if(s[n-nowp]=='0'&&nowp==y) cnt++;
        nowp++;
    }
    printf("%d\n",cnt);
}
int main()
{
    Solve();
    return 0;
}