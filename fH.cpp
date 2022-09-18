#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int Maxn=5000010;
long long ans=9223372036854775806ll;
bool Not_prime[10000010];
int prime[10000010];
int len=0,len2=0;
struct PRI{long long num,cnt;}Pri[Maxn];
void Linear_sieve_prime(long long x)
{
	Not_prime[1]=1;
	for(int i=2;i<=x;i++)
	{
		if(Not_prime[i]==0)
			prime[++len]=i;
		for(int j=1;j<=len;j++)
		{
			if(prime[j]*i>x)
				break ;
			Not_prime[i*prime[j]]=1;
			if(!(i%prime[j])) break ;
		}
	}
}
void Separate(long long x)
{
    for(int i=1;i<=len;i++)
    {
        if(prime[i]>x) break ;
        if(!(x%prime[i])) 
        {
            Pri[++len2].num=prime[i];
            while(!(x%prime[i])) x/=prime[i],Pri[len2].cnt++;
        }
    }
    if(x>1) Pri[++len2].num=x,Pri[len2].cnt=1;
}
void Solve()
{
    long long n,ki;
    cin>>n>>ki;
    Linear_sieve_prime(2000000);
    Separate(ki);
    //cout<<len2<<endl;
    for(int i=1;i<=len2;i++)
    {
        long long in=n,CNT=0;
        while(in>0) in/=Pri[i].num,CNT+=in;
        ans=min(ans,CNT/Pri[i].cnt);
        //cout<<"sss"<<endl;
    }
    cout<<ans<<endl;
}
int main()
{
    Solve();
    system("pause");
    return 0;
}