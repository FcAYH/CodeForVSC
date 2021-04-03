#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int Inf=0x3f3f3f3f;
const int Maxn=101000;
int n;
int h[Maxn];
int Id[Maxn];
int Ans[Maxn];
int Stack[Maxn];
void Solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&h[i]);
    int top=0;
    Stack[++top]=Inf;Id[top]=n+1;
    for(int i=n;i>=1;i--)
    {
        while(Stack[top]<=h[i]&&top>0) top--;
        Ans[i]=Id[top]-i-1;
        Stack[++top]=h[i],Id[top]=i;
    }
    for(int i=1;i<=n;i++) 
    {
        (Ans[i]>h[i])?printf("%d ",h[i]):printf("%d ",Ans[i]);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}