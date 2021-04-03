#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
const int Maxn=5002;
typedef long long ll;
using namespace std;
struct M{
    int pos,x;
}Max[Maxn];
int mar[Maxn][Maxn],ma[Maxn][Maxn],n,a,b,ha,hi,ta,ti,ans;
inline int gcd(int x,int y){return !y?x:gcd(y,x%y);}
void Solve()
{
    scanf("%d%d%d",&a,&b,&n);
    for(int i=1;i<=a;++i)
        for(int j=1;j<=b;++j) mar[i][j]=i*j/gcd(i,j);
    for(int i=1;i<=a;++i)
    {
        ha=hi=1;ta=ti=0;
        for(int j=1;j<=b;++j)
        {
            if(ha<=ta&&Max[ha].pos<j-(n-1)) ha++;
            while(ha<=ta&&mar[i][j]>Max[ta].x) ta--;
            Max[++ta].x=mar[i][j],Max[ta].pos=j;
            if(j-(n-1)>0) ma[i][j-(n-1)]=Max[ha].x;
        }
    }
    for(int j=1;j<=b-(n-1);++j)
    {
        ha=hi=1;ta=ti=0;
        for(int i=1;i<=a;++i)
        {  
            if(ha<=ta&&Max[ha].pos<i-(n-1)) ha++;
            while(ha<=ta&&ma[i][j]>Max[ta].x) ta--;
            Max[++ta].x=ma[i][j],Max[ta].pos=i;
            if(i-(n-1)>0) ma[i-(n-1)][j]=Max[ha].x;
        } 
    } 
    ll ans=0ll;
    for(int i=1;i<=a-(n-1);++i)
        for(int j=1;j<=b-(n-1);++j) ans+=(ll)ma[i][j]; 
    printf("%lld",ans);
}
int main()
{
    Solve();
    system("pause");
    return 0;   
}
