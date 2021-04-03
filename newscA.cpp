#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MaxI=100000000ll;
string s1,s2;
void Dynamic_P()
{
	int m=s1.length(),n=s2.length();
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			Dp1[i][j]=max(Dp1[i-1][j],Dp1[i-1][j-1]+s1[i]);
}
void Solve()
{
    cin>>T;
	while(T--)
	{
		cin>>s1>>s2>>k;
		Dynamic_P();
	}
}
int main()
{
    Solve();
    return 0;
}