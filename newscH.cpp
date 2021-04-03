#include<cstdio>
#include<iostream>
#include<cstring>
#define debug(x) cout<<#x<<"="<<x<<endl;
using namespace std;
typedef long long ll;
const ll Mod=1000000007;
int n;
ll m,ans=0ll;
struct Matrix
{
	ll M[5][5];
};
Matrix f;
Matrix Multi(Matrix a,Matrix b)
{
	Matrix Ret;
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=2;j++)
		{
			Ret.M[i][j]=0ll;
			for(int k=1;k<=2;k++)
			{
				Ret.M[i][j]=(Ret.M[i][j]+a.M[i][k]*b.M[k][j])%Mod;
			}
		}	
	}
	return Ret;
}
Matrix Quick_pow(Matrix f,ll k)
{
	Matrix Ret=f,b=f;
	while(k>0ll)
	{
		if(k%2ll==1ll)
			Ret=Multi(Ret,b);
		b=Multi(b,b);
		k/=2ll;
	}
	return Ret;
}
void Init()
{
    f.M[1][1]=1ll; f.M[1][2]=1ll;
	f.M[2][1]=1ll; f.M[2][2]=0ll;
}
void Solve()
{
    cin>>n>>m;
    if(m==0) 
    {
        ans=n; 
        cout<<ans<<endl; return ;
    }
    int a;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(a==3)
        {   
            if(m==1ll) ans+=2ll,ans%=Mod;
            else if(m==2ll) ans+=4ll,ans%=Mod;
            else
            {
                Init();
                f=Quick_pow(f,m-4ll);
                ans+=2ll*f.M[1][1];
                ans%=Mod;
                Init();
                f=Quick_pow(f,m-3ll);
                ans+=4ll*f.M[1][1];
                ans%=Mod;
            }
        }
        else if(a==2)
        {
            if(m==1ll) ans+=2ll;
            else
            {
                if(m==2ll) ans+=2ll,ans%=Mod;
                else if(m==3ll) ans+=4ll,ans%=Mod;
                else
                {
                    Init();
                    f=Quick_pow(f,m-5ll);
                    ans+=2ll*f.M[1][1];
                    ans%=Mod;
                    Init();
                    f=Quick_pow(f,m-4ll);
                    ans+=4ll*f.M[1][1];
                    ans%=Mod;
                } 
            }
        }
        else continue ;
    }
	cout<<ans<<endl;
}
int main()
{
    freopen("hearthstone10.in","r",stdin);
    freopen("hearthstone10.out","w",stdout);
    Solve();
    return 0;
}