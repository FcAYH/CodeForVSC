#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
long long n,ans,p=1e9+7,f[300300],pre[300300][80][2];
long long pow(long long x,long long y)
{
	long long ans=1;
	while(y)
	{
		if(y&1)
			ans=ans*x;
		x=x*x;
		y>>=1;
	}
	return ans;
}
int main()
{
	cin>>n;
	for(long long i=1; i<=n; i++)
		cin>>f[i];
	for(long long i=1; i<=n; i++)
		for(long long j=0; j<=62; j++)
		{
			long long x= f[i]/pow(2,j);
			if(x%(long long)2)	pre[i][j][1] = pre[i-1][j][1]+1 , pre[i][j][0] = pre[i-1][j][0];
			else				pre[i][j][1] = pre[i-1][j][1] , pre[i][j][0] = pre[i-1][j][0]+1;
		}
	for(long long i=1; i<n; i++)
		for(long long j=0; j<=62; j++)
		{
			long long x= f[i]/pow(2,j);
			if(x%(long long)2)	ans = ( ans+ (pre[n][j][0]-pre[i][j][0]) * (pow(2ll,j)%p) )%p;
			else            	ans = ( ans+ (pre[n][j][1]-pre[i][j][1]) * (pow(2ll,j)%p) )%p; 
		}
	cout<<ans%p;
	return 0;
}