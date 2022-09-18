#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int Maxn=100000;
int n;
int qpl[Maxn];
int jl[Maxn];
void print()
{
	for(int i=1;i<=n;i++) printf("%d ",jl[i]);
	printf("\n");
}
void ss(int m)
{
	for(int i=1;i<=n;i++)
	{
		if(!qpl[i])
		{
			qpl[i]=i;
			jl[m]=qpl[i];
			if(n==m) print();
			else ss(m+1);
			qpl[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	ss(1);
	return 0;
}