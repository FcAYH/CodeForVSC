#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef unsigned long long ll;
int t;
double f[80];
double x,y;
void Solve()
{
	f[1] = 2;
	for(int i=2;i<=64;i++)	
	{
		double X=2;
		f[i]=f[i-1]*X;
	}
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        int cnt=0;
        while(x<y) 
		{
			x*=(double)2;
			cnt++;
		}
		double gap=x-y;
        int cm=cnt;
        while(gap>0&&cm>0)
        {
        	if(gap/f[cm]>=1)
        	{
        		int X=gap/f[cm];
        		cnt+=X;
        		gap=gap-X*f[cm];
			}
			cm--;
		}
		cout<<cnt<<endl;
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
100
1 10000000000000000000
*/