#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Maxn=10001;
int n,b,num=0;
int Pre[Maxn];
int val[Maxn];
int a[Maxn];
inline int cmp(int a,int b){return a<b;}
void Solve()
{
    scanf("%d%d",&n,&b);
    Pre[0]=0;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        if(a[i]%2) Pre[i]=Pre[i-1]+1;
        else Pre[i]=Pre[i-1]-1;
    }
    for(int i=1;i<n;i++) if(!Pre[i]) val[++num]=abs(a[i]-a[i+1]);
    if(!num) printf("0");
    else
    {
        sort(val+1,val+1+num,cmp);
        int cnt=0;
        for(int i=1;i<=num;i++)
        {
            cnt+=val[i];
            if(cnt>b) 
            {
                printf("%d",i-1); return ;
            }
        }
        printf("%d",num);
    }
    
}
int main()
{
    Solve();
    system("pause");
    return 0;
}