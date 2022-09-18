#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Maxn=110;
int n,m;
int f[Maxn],g[Maxn];
void Solve()
{
    scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d",&f[i]);
	sort(f+1,f+1+m);
	int cnt= 1;
	for(int i=1;i<=m;i++)
	{
        if(f[i]!=f[i+1]) g[++g[0]]=cnt,cnt=1;
		else cnt++;
    }
    sort(g+1,g+1+g[0]);
	for(int i=100;i>=1;i--)
	{
		cnt=0;
		for(int j=1;j<=g[0];j++) cnt+=g[j]/i;
		if(cnt>=n)
		{
			printf("%d",i); return ;
		}
	}
	printf("0");
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
