#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
long long f[1010100];
int main()
{
	int t;
	for(long long i=1; i<=5e5; i++)
		f[i]=i*i*i;
	scanf("%d",&t);
	while(t--)
	{
		long long x;
		bool flag=0;
		scanf("%lld",&x);
		for(int i=1; i<=5e5; i++)
		{
			long long y=f[i]-x;
			int l=1,r=5e5,pos=0;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(f[mid]>=y)
				{
					pos=mid;
					r=mid-1;
				}
				else	l=mid+1;
			}
			if(f[pos]==y)
			{
				flag=1;
				break;
			}
		}
		if(flag)	printf("Davones NB\n");
		else	printf("Oh,on!\n");
	}
	return 0;
}