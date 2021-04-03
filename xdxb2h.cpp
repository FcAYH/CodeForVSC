#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Maxn=303030;
int n;
int f[Maxn];
void Solve()
{
    scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&f[i]);
	int p1=1,p2=n;
	int x=0,cnt=0;
	while(1)
	{
		while((f[p1]<f[p2]&&f[p1]>x)||(f[p1]>x&&f[p2]<x)) cnt++,x=f[p1],p1++;
		while((f[p1]>f[p2]&&f[p2]>x)||(f[p1]<x&&f[p2]>x)) cnt++,x=f[p2],p2--;
        //cout<<p1<<" "<<p2<<endl;
		if((f[p1]==f[p2])||(f[p1]<=x&&f[p2]<=x)) break;
	}
//	cout<<cnt<<endl;
	if(f[p1]==f[p2]&&f[p1]>x)
	{
		int t1=x,t2=x,ans1=cnt,ans2=cnt;
		while(f[p1]>t1) ans1++,t1=f[p1],p1++;
		while(f[p2]>t2) ans2++,t2=f[p2],p2--;
		cnt=max(ans1,ans2);
	}
	printf("%d",cnt);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}

/*
7
1 3 5 6 5 4 2

3
2 2 2

5 
10 7 5 1 74
*/