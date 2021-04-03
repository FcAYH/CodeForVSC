#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,k;
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Solve()
{
    t=read();
    while(t--)
    {
        n=read(); k=read();
        int ALL=2*n*(n+1),HalA=n*(n+1);
        if(ALL%k) printf("-1\n"); 
        else if(k==1||n==1) printf("-1\n");
        else if(!(n%k))
        {
            for(int i=1;i<=n+1;i++)
            {  
                int nowc=i%k;
                if(nowc==0) nowc=k;
                for(int j=1;j<=n;j++) 
                {
                    printf("%d ",nowc);
                    nowc++;
                    if(nowc==k+1) nowc=1;
                }
                puts("");
            }
            for(int i=1;i<=n+1;i++)
            {
                int nowc=i%k;
                if(nowc==0) nowc=k;
                for(int j=1;j<=n;j++) 
                {
                    printf("%d ",nowc);
                    nowc++;
                    if(nowc==k+1) nowc=1;
                }
                puts("");
            }
        }
        else if(!(HalA%k))
        { 
            int nowc=1;
            for(int i=1;i<=n+1;i++)
            {  
                for(int j=1;j<=n;j++) 
                {
                    printf("%d ",nowc);
                    nowc++;
                    if(nowc==k+1) nowc=1;
                }
                puts("");
            }
            nowc=1;
            for(int i=1;i<=n+1;i++)
            {
                for(int j=1;j<=n;j++) 
                {
                    printf("%d ",nowc);
                    nowc++;
                    if(nowc==k+1) nowc=1;
                }
                puts("");
            }
        }
        else
        {
            int nowc=1;
            for(int i=1;i<=n+1;i++)
            {  
                for(int j=1;j<=n;j++) 
                {
                    printf("%d ",nowc);
                    nowc++;
                    if(nowc==k+1) nowc=1;
                }
                puts("");
            }
            for(int i=1;i<=n+1;i++)
            {
                for(int j=1;j<=n;j++) 
                {
                    printf("%d ",nowc);
                    nowc++;
                    if(nowc==k+1) nowc=1;
                }
                puts("");
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