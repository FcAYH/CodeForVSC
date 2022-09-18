#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve()
{
    int A[3];
    scanf("%d%d%d",&A[0],&A[1],&A[2]);
    sort(A,A+3);
    int a=A[0],b=A[1],c=A[2];
    char s[10];
    cin>>s;
    if(s[0]=='A') printf("%d ",a);
    if(s[0]=='B') printf("%d ",b);
    if(s[0]=='C') printf("%d ",c);
    if(s[1]=='A') printf("%d ",a);
    if(s[1]=='B') printf("%d ",b);
    if(s[1]=='C') printf("%d ",c);
    if(s[2]=='A') printf("%d ",a);
    if(s[2]=='B') printf("%d ",b);
    if(s[2]=='C') printf("%d ",c);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
如果三条线段不能组成一个三角形，输出Not triangle；
如果是直角三角形，输出Right triangle；
如果是锐角三角形，输出Acute triangle；
如果是钝角三角形，输出Obtuse triangle；
如果是等腰三角形，输出Isosceles triangle；
如果是等边三角形，输出Equilateral triangle。
*/