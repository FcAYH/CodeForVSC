#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int T,n,k,w;
ll sum;
long double pi = 3.14159265358979323846,t;

int Ceil(long double x)
{
	if(x>(int)x) return (int)x+1;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&k,&n);
		t=k*pi-1;
		sum=1ll*n*(n+1)/2;
		long double now=t,last=1;
		for(int i=0;last<=n;last=now,now+=t,i++)
		{
			int l=Ceil(last),r=min(n,(int)(now));
			if(l>n) break;
			sum+=1ll*i*(r-l+1);
		}
		printf("%lld\n",sum);
	}
    system("pause");
	return 0;
}
/*
1
1
1000000000
733471103696000343

733471103695601080

1
1
3333 1000000000
*/