#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())

signed main(){

	lli n;
	cin>>n;

	vector<lli> a(n);
	REP(i,0,n)cin>>a[i];


	lli data[100];
	REP(i,0,100)data[i]=0;

	lli sum=0;
	for(lli i=0;i<n;i++){
		if(i!=0){
			lli next = a[i];
			lli size = i;
			lli two=1;
			for(lli bit=0;bit<61;bit++){

				if(next&(1LL<<bit)){
					sum += two*(size-data[bit]);
				}
				else{
					sum += two*data[bit];
				}

				sum%=MOD;
				two*=2;
				two%=MOD;
			}
		}

		lli now = a[i];
		for(lli bit=0;bit<61;bit++){
			if(now&(1LL<<bit)){
				data[bit]++;
			}
		}
	}
	cout<<sum<<endl;


	return 0;
}
