#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MaxI=100000000ll;

void Solve()
{
	int t;
	//cin>>t;
	while(scanf("%d",&t)!=EOF)
	{
		if(!t) break ;
    	while(t--)
		{
			ll n,cnt=0ll;
			cin>>n;
    		while(n>0)
			{
    	   		n/=2;
       			cnt+=n;
    		}
    		cout<<cnt<<endl;
		}
	}
	/*
    while(1)
	{
		ll t;
		cin>>t;
		if(t==0ll) break;
		while(t--)
		{
			ll n,cnt=0ll;
			cin>>n;
			for(ll i=2; i<=MaxI; i<<=1) cnt+=n/i;
			cout<<cnt<<endl;
		}
	}
	*/
}
int main()
{
    Solve();
    return 0;
}