#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Maxn=200000;
int t,n,s;
int a[Maxn];
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
        n=read(),s=read();
        for(int i=1;i<=n;i++) a[i]=read();
        int flag=0,cnt=0;
        int sum=0,maxt=0;
        for(int i=1;i<=n;i++)
        {
            sum+=a[i];
            if(!flag) if(a[i]>maxt) maxt=a[i],cnt=i;
            if(sum>s&&!flag) sum-=maxt,flag=1;
            if(sum>=s&&flag) break ; 
        }
        if(flag) printf("%d\n",cnt);
        else printf("0\n");
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}