#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Maxn=15;
int n,m,ans;
int s[Maxn+10][Maxn+10];
bool vis[Maxn+10];
int cnt[Maxn+10];
void dfs(int x,int tot)
{
	if(x==n+1)
	{
		bool flag=1;
		for(int i=1;i<=n;i++)
		{	
            if(vis[i])
			{
                for(int j=1;j<=n;j++)
			    	if((s[i][j]==1&&!vis[j])||(s[i][j]==0&&vis[j])) flag=0;
            }
        }
        if(flag) ans=max(ans,tot);
		return;
	}
	vis[x]=1,dfs(x+1,tot+1);
	vis[x]=0,dfs(x+1,tot);
}
void Solve()
{
    scanf("%d",&n);
	for(int i=1;i<=15;i++)
		for(int j=1;j<=15;j++) s[i][j]=-1;
    int a,b;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m);
		for(int j=1;j<=m;j++) scanf("%d%d",&a,&b),s[i][a]=b;
	}
	dfs(1,0);
	printf("%d",ans);
}
int main()
{
    Solve();
	return 0;
} 