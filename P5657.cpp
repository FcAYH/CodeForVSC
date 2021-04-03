#include<cstdio>
#include<iostream>
#include<cstring>
#define debug(x) cout<<#x<<"="<<x<<endl;
using namespace std;
using ll=unsigned long long;
ll Pow[66];
ll n,k;
inline ll read()
{
    ll fl=1ll,rt=0ll; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1ll; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10ll+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Init()
{
    Pow[0]=1;
    for(int i=1;i<=64;i++) Pow[i]=Pow[i-1]*2ll;
}
void Solve()
{
    Init();
    n=read(); k=read();
    ll cnt=n-1;
    bool si=1;
    bool flag=0;
    for(int i=1;i<=n;i++) 
    {
        //debug(si); debug(k); debug(flag); debug(Pow[cnt]);
        if(si)
        {
            if(Pow[cnt]>k)
            {
                cout<<"0"; if(flag==1) flag=0,si^=1;
            }
            else 
            {
                cout<<"1"; if(flag==0) flag=1,si^=1;
            }
        }
        else
        {
            if(Pow[cnt]>k)
            {
                cout<<"1"; if(flag==1) flag=0,si^=1;
            }
            else 
            {
                cout<<"0"; if(flag==0) flag=1,si^=1;
            }
        }
        if(k>=Pow[cnt]) k-=Pow[cnt]; cnt--;
    }
    puts("");
}
int main()
{
    Solve();
    return 0;
}