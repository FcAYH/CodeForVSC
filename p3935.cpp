#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MaxN=60000000;
const ll Mod=998244353ll;
ll l,r;
void Solve()
{
    scanf("%lld%lld",&l,&r);
    ll ans=0ll;
    ans=(l==1)?2ll*(r-l)+1ll:2ll*(r-l+1ll);
    ans=ans-ans/Mod*Mod;
    for(register ll i=2;i<=(ll)sqrt(r);i++)
    {
        ll left=i+1,right=r;
        ll Tl=0,Tr=MaxN;
        while(left<=right)
        {
            ll mid=(left+right)>>1;
            if(i*mid>=l) Tl=mid,right=mid-1;
            else left=mid+1;
        }
        left=0,right=MaxN;
        while(left<=right)
        {
            ll mid=(left+right)>>1;
            if(i*mid<=r) Tr=mid,left=mid+1;
            else right=mid-1;
        }
        if(i*i>=l&&i*i<=r) ans+=1;
        if(Tl!=0&&Tr!=MaxN)ans+=2*(Tr-Tl+1),ans=ans-ans/Mod*Mod;
 //       cout<<Tl<<" "<<Tr<<" "<<ans<<endl;
    }
           
    printf("%lld",ans%Mod);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}

/*
645486 78698954


436011121


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MaxN=20000000;
const ll Mod=998244353ll;
ll l,r;
void Solve()
{
    scanf("%lld%lld",&l,&r);
    ll ans1=0ll,ans2=0ll;
    ll last=0;
    l--;
    for(register ll i=1;i<=l;i=last+1)
    {
        ll len=l/(l/i)-last; last=l/(l/i); 
        ans1+=len*(l/i); ans1%=Mod;
    }
    last=0;
    for(register ll i=1;i<=r;i=last+1)
    {
        ll len=r/(r/i)-last; last=r/(r/i);
        ans2+=len*(r/i); ans2%=Mod;
    }
    printf("%lld",(ans2-ans1+Mod)%Mod);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}

ll left=i+1,right=r;
        ll Tl=i+1,Tr=r;
        while(left<=right)
        {
            ll mid=(left+right)>>1;
            if(i*mid>=l) Tl=mid,right=mid-1;
            else left=mid+1;
        }
        left=i+1,right=r;
        while(left<=right)
        {
            ll mid=(left+right)>>1;
            if(i*mid<=r) Tr=mid,left=mid+1;
            else right=mid-1;
        }
        printf("%lld  %lld\n",Tl,Tr);
        if(i*i>=l&&i*i<=r) ans+=1;
        ans+=2*(Tr-Tl+1),ans=ans-ans/Mod*Mod;
*/