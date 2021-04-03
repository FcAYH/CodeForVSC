#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=10010;
int T;
double ans[Maxn];
struct pro{int q,id;}s[Maxn];
bool cmp(pro a,pro b){return a.q<b.q;}
int main()
{
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d",&s[i].q);
		s[i].id=i;
	}
    sort(s+1,s+1+T,cmp);
	int p=1;
	double Ans=0;
	for(int i=1;i<=s[T].q;i++)
	{
		Ans+=(double)1/i;
		while(i==s[p].q) ans[s[p].id]=Ans,p++;
	}
	for(int i=1;i<=T;i++) printf("Case %d: %.10lf\n",i,ans[i]);
    system("pause");
	return 0;
}