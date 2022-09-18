#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=3000010;
int n,top=0;
int a[Maxn];
int Ans[Maxn];
int Id[Maxn];
int Stack[Maxn];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Solve()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    Stack[++top]=a[1];
    Id[top]=1; 
    for(int i=2;i<=n;i++)
    {
        while(Stack[top]<a[i]&&top) Ans[Id[top]]=i,top--;
        Stack[++top]=a[i],Id[top]=i;
    }
    while(top) Ans[Id[top]]=0,top--;
    for(int i=1;i<=n;i++) printf("%d ",Ans[i]);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}