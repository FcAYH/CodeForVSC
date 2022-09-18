#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

void Solve()
{
    int t;
	scanf("%d",&t);
	while(t--)
	{
		long long a,b,c,ans=-1e18;
		scanf("%lld%lld%lld",&a,&b,&c);
		ans=max(ans,a+b+c);
		
		ans=max(ans,(a+b)*c);
		ans=max(ans,a*(b+c));
		ans=max(ans,(a+c)*b);
		
		ans=max(ans,a*b+c);
		ans=max(ans,a*c+b);
		ans=max(ans,b*c+a);
		
		ans=max(ans,a*b*c);
		
		printf("%lld\n",ans);
	}
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
