#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
double a,b;
inline bool Check_Esp(double x,double y)
{
    return abs((x-y))<=0.03;
}
void Make_Graph()
{
    for(double i=100;i>0;i--)
    {
        for(double j=0;j<=100;j++)
        {
            if(j==0){cout<<"| "; continue ;}
            if(Check_Esp(a*(j/10)+b,i/10)) cout<<". ";
            else cout<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=100;i++) cout<<"一";
}
void Solve()
{
    cin>>a>>b;
    Make_Graph();
}
int main()
{
    freopen("Graph.txt","w",stdout);
    Solve();
    system("puase");
    return 0;
}