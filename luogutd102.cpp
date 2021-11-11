#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=300000;
int len=0;
int Not_p[Maxn];
int prime[Maxn];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Prime_Ini()
{
    Not_p[1]=1;
    for(int i=2;i<=200000;i++)
    {
        if(!Not_p[i]) prime[++len]=i;
        for(int j=1;j<=len;j++) 
        {
            if(i*prime[j]>200000) break ;
            Not_p[i*prime[j]]=1;
            if(!(i%prime[j])) break ;
        }
    }
}
void Solve()
{
    int n;
    n=read();
    
    for(int x=100;x>=1;x--)
    {
        for(int k=1;k<=n;k++)
        {
            int in=n;
            int sum=52*(7*x+21*k);
            if(sum==n) 
            {
                printf("%d\n%d",x,k); 
                return ;
            }
        }
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
