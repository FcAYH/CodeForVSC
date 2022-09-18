#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
queue <int> q;
int f[2020200],ans[2020200],t,n;
int main()
{
	for(int i=1; i<=4e5; i++)
		ans[i]=2e9;
	for(int i=1; i<=1000; i++)
		if(i*i<=4e5)
		{
			f[++f[0]]=i*i;
			q.push(i*i);
			ans[i*i]=1;
		}
	while(!q.empty())
	{
		int x=q.front();
		q.pop(); 
		for(int i=1; i<=f[0]; i++)
			if(x+f[i]<=4e5)
				if(ans[x]+1<ans[x+f[i]])
				{
					ans[x+f[i]]=ans[x]+1;
					q.push(x+f[i]);
				}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",ans[n]); 
	}
	return 0;
}