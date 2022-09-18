#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int Maxn=20000000;
bool Not_prime[20000010];
int prime[20000010];
int n,len=0;
void Linear_sieve_prime()
{
	Not_prime[1]=0;
	for(int i=2;i<=11000000;i++)
	{
		if(Not_prime[i]==0)
			prime[++len]=i;
		for(int j=1;j<=len;j++)
		{
			if(prime[j]*i>11000000)
				break ;
			Not_prime[i*prime[j]]=1;
			if(!(i%prime[j])) break ;
		}
	}
}
void Solve()
{
    Linear_sieve_prime();
    scanf("%d",&n);
    for(int i=n+1;i<=Maxn;i++)
    {
        //printf("%d %d\n",Not_prime[9],Not_prime[8]);
        if(Not_prime[i-n]&&Not_prime[i]) 
        {
            printf("%d %d\n",i,i-n);
            break ;
        }
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}