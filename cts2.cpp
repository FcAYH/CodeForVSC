#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,ans=0;
int eig[10];
void Change(int x)
{
    int cnt=1;
    while(x)
    {
        eig[cnt]=x%8,x/=8,cnt++;
    }
    for(int i=1;i<cnt;i++) if(eig[i]==7) ans++;
}
void Solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) Change(i);
    cout<<ans<<endl;
}
int main()
{
    Solve();
    return 0;
}