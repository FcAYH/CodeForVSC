#include<iostream>

using namespace std;

void main()
{
    int a,b;
    cin>>a>>b;
    int r=a%b;
    if(a<b) swap(a,b);
    while(r!=0) r=a%b,b=b-r;
    cout<<b<<endl;
}