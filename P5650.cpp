#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Maxn=101000;
const int Inf=0x3f3f3f3f;
char s[Maxn];
int A[Maxn];
void Dynamic_P(int len)
{
    int cs=-Inf,ans=-Inf;
    for(int i=0;i<len;i++)
	{
		cs=max(A[i],A[i]+cs);
		ans=max(ans,cs);
	}
    printf("%d\n",ans);
}
void Solve()
{
    cin>>s;
    int len=strlen(s);
    for(int i=0;i<len;i++) s[i]=='0'?A[i]=1:A[i]=-1;
    Dynamic_P(len);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}