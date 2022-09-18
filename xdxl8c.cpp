#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=100101;
int n,s;
int a[Maxn];
ll coin[Maxn];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Solve()
{
    n=read(); s=read();
    for(int i=1;i<=n;i++) a[i]=read();
    coin[1]=1ll;
    int cnt=n+1;
    for(int i=2;i<=n+1;i++) 
    {
        coin[i]=coin[i-1]*a[i-1];
        if(coin[i]>s) 
        {
            cnt=i-1; break ;
        }
    }
    int ans=0;
    while(s)
    {
        ans+=s/coin[cnt];
        s=s%coin[cnt];
        cnt--;
    }
    printf("%d",ans);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}