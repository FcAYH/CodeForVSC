#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int Maxn=10001;
int n;
int A[Maxn];
int B[Maxn];
int C[Maxn];
void Solve()
{
    cin>>n;
    int a,cnt1=0,cnt2=0,cnt3=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a;
        if((a%2==0)&&(a%5!=0)) A[++cnt1]=a;
        if(a%2==0) B[++cnt2]=a;
        if(a%5==0) C[++cnt3]=a;
    }
    for(int i=1;i<=cnt1;i++) cout<<A[i]<<" ";
    cout<<endl;
    for(int i=1;i<=cnt2;i++) cout<<B[i]<<" ";
    cout<<endl;
    for(int i=1;i<=cnt3;i++) cout<<C[i]<<" ";
    cout<<endl;
 
}
int main()
{
    Solve();
    return 0;
}