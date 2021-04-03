#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
void Solve()
{
    double n,pri;
    cin>>n>>pri;
    double sum=n*pri;
    if(n<50) cout<<sum<<endl;
    else if(n<100) cout<<sum*0.9<<endl;
    else cout<<sum*0.85<<endl;
}
int main()
{
    Solve();
    system("pause");
    return 0;
}