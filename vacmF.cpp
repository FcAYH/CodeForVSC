#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
double sum=0;
double f[1000100];
int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%lf",&f[i]);
	sort(f+1,f+1+n);
	for(int i=1; i<n; i++)
		sum+=f[i];
	if(f[n]>=sum)
		printf("%.1lf\n",sum);
	else
		printf("%.1lf\n",(sum+f[n])/2.0);
    //system("pause");
	return 0;
}