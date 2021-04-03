#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
long long f[60600];
int Maxl,Maxr;
void work(int pos)
{
	long long l,r;
	scanf("%lld",&l);
	if(l!=-1)
	{
		Maxl=min(Maxl,pos-1);
		f[pos-1]+=l;
		work(pos-1);
	}
	scanf("%lld",&r);
	if(r!=-1)
	{
		Maxr=max(Maxr,pos+1);
		f[pos+1]+=r;
		work(pos+1);
	}
}
int main()
{
	freopen("leaves.in","r",stdin);
	freopen("leaves.out","w",stdout);
	while(1)
	{
		long long x;
		Maxr=150,Maxl=150;
		for(int i=0; i<=300; i++)	f[i]=0;
		scanf("%lld",&x);
		if(x!=-1) f[150]=x;
		else break;
		work(150);
		printf("%lld",f[Maxl]);
		for(int i=Maxl+1; i<=Maxr; i++)	printf(" %lld",f[i]);
		printf("\n");
	}
	return 0;
}