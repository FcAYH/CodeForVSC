#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MaxN=4000001;
const int Maxn=20010;
int n,cnt=0;
int prime[MaxN+10];
ll phi[MaxN+10];
int Not_p[MaxN+10];
ll Ans[MaxN+10];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Prime_Ini()
{
    Not_p[1]=1; phi[1]=1ll;
    for(int i=1;i<=MaxN;i++)
    {
        if(!Not_p[i]) prime[++cnt]=i,phi[i]=i-1;
        for(int j=1;j<=cnt;j++)
        {
            if(i*prime[j]>MaxN) break ;
            Not_p[i*prime[j]]=1;
            phi[i*prime[j]]=phi[i]*phi[prime[j]];
            if(!(i%prime[j]))
            {
                phi[i*prime[j]]=phi[i]*prime[j];
                break ;
            }
        }
    }
    for(int x=1;x<=MaxN;x++)
    {
        for(int j=x*2;j<=MaxN;j+=x) Ans[j]+=(ll)x*phi[j/x];
    }
    for(int i=2;i<=MaxN;i++) Ans[i]+=Ans[i-1];
}
void Solve()
{
    Prime_Ini();
    n=read();
    while(n)
    {
        printf("%lld\n",Ans[n]);
        n=read();
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
[P2568 GCD](https://www.luogu.com.cn/problem/P2568)
    
    [P2303 [SDOI2012]Longge的问题](https://www.luogu.com.cn/problem/P2303)
    
    [UVA11424 GCD-Extreme(I)](https://www.luogu.com.cn/problem/UVA11424)
    
    [SP3871 GCDEX-GCD Extreme](https://www.luogu.com.cn/problem/SP3871)
    
    [UVA11426 GCD-Extreme(II)](https://www.luogu.com.cn/problem/UVA11426)
*/