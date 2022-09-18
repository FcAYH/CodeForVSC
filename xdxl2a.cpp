#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>


#include <algorithm>
#include <stack>
#include <iomanip>

#include <cmath>

using namespace std;
typedef long long ll;
const ll Mod=140737488355328ll;
map<string,ll> Map;
string ope,opa,opb;
ll Mul_Mod(ll x,ll y)
{
    ll ret=0;
    while(y)
    {
        if(y&1) ret=(ret+x)%Mod;
        y>>=1,x=(x+x)%Mod;
    }
    return ret;
}
void Solve()
{
    while(cin>>ope)
    {
        cin>>opa>>opb;
        if(ope[0]=='d'&&ope[1]=='e')
        {
            ll num=0;
            int len=opb.length();
            for(int i=0;i<len;i++) num=num*10+opb[i]-'0';
            Map[opa]=num;
        }
        else if(ope[0]=='a')
        {
            Map[opa]+=Map[opb],Map[opa]%=Mod;
        }
        else if(ope[0]=='s')
        {
            Map[opa]=(Map[opa]-Map[opb]+Mod)%Mod;
        }
        else if(ope[0]=='m'&&ope[1]=='u')
        {
            Map[opa]=Mul_Mod(Map[opa],Map[opb]);
        }
        else if(ope[0]=='d'&&ope[1]=='i')
        {
            Map[opa]/=Map[opb],Map[opa]=(Map[opa]+Mod)%Mod;
        }
        else if(ope[0]=='m'&&ope[1]=='o')
        {
            Map[opa]%=Map[opb],Map[opa]%=Mod;
        }
        cout<<opa<<" = "<<Map[opa]<<endl;
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}