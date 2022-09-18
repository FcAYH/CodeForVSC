#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n,j;
	scanf("%d",&n);
	for(int i=2;i<sqrt(n);i++) if(n%i==0) printf("%d\n",n/i);
	return 0;
}