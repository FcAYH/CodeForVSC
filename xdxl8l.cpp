#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b;
void Solve()
{
    scanf("%d%d",&a,&b);
    if(a==1)
    {
        printf("%d\n",b);
        for(int i=b;i>=1;i--) printf("%d ",i);
    }
    else if(b==1)
    {
        printf("%d\n",a);
        for(int i=1;i<=a;i++) printf("%d ",i);
    }
    else
    {
        printf("%d\n",a*b);
        int n=a*b;

        for(int i=1;i<=b;i++)
        {
            for(int j=n-i*a+1;j<=n-(i-1)*a;j++) printf("%d ",j);
        }
    }
    
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
if(b%2)
        {
            int beginb=b/2;
            int begina=beginb+1;
            for(int i=begina;i<=begina+a/2-1;i++) printf("%d ",i);
            for(int i=n;i>=n-(b/2);i--) printf("%d ",i);
            for(int i=beginb;i>=1;i--) printf("%d ",i);
            for(int i=begina+a/2;i<=begina+a-1;i++) printf("%d ",i); 
        }
        else
        {
            int beginb=b/2;
            int begina=beginb+1;
            for(int i=begina;i<=begina+a/2-1;i++) printf("%d ",i);
            for(int i=n;i>=n-(b/2)+1;i--) printf("%d ",i);
            for(int i=beginb;i>=1;i--) printf("%d ",i);
            for(int i=begina+a/2;i<=begina+a-1;i++) printf("%d ",i); 
        }

        printf("%d\n",a+b);
        int n=a+b;

        int beginb=b/2;
        int begina=beginb+1;
        for(int i=begina;i<=begina+a/2-1;i++) printf("%d ",i);
        for(int i=n;i>=n-(b-(b/2))+1;i--) printf("%d ",i);
        for(int i=beginb;i>=1;i--) printf("%d ",i);
        for(int i=begina+a/2;i<=begina+a-1;i++) printf("%d ",i); 
*/