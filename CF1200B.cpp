#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=1000;
int n,m,k;
int h[Maxn];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Solve()
{
    int T=read();
    while(T--)
    {
        n=read(),m=read(),k=read();
        for(int i=1;i<=n;i++) h[i]=read();
        int flag=1;
        for(int i=1;i<n;i++)
        {
            if(h[i+1]-h[i]<=k) 
            {
                if(h[i+1]>=h[i]) m+=min(h[i],k-(h[i+1]-h[i]));
                else m+=min(h[i],h[i]-h[i+1]+k);
            }
            else
            {
                if(h[i]+m>=h[i+1]-k) m-=h[i+1]-k-h[i];
                else 
                {
                    printf("NO\n"); flag=0; break ;
                }
            }
        }
        if(flag) printf("YES\n");
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
1
10 50 160
319 47 107 192 866 475 139 594 636 345
*/