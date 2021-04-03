#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=1000;
int n;
int num=0;
int vis[Maxn];
int Val[Maxn];
int Ans[Maxn];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
inline int cmp(int a,int b){return a<b;}
inline int cmp2(int a,int b){return a>b;}
void Solve()
{   
    n=read();
    int x,y,z;
    x=read(),y=read(),z=read();
    int Nkl=x+y+z-min(x,min(y,z));
    for(int i=2;i<=n;i++) Val[++num]=read(),Val[++num]=read(),Val[++num]=read();
    sort(Val+1,Val+1+3*(n-1),cmp);
    int cnt=0;
    Ans[++cnt]=Nkl;
    for(int i=3*(n-1);i>=1;i--)
    {
        if(vis[i]) continue ;
        int val=Val[i];
        for(int j=i-1;j>=1;j--)
        {
            if(vis[j]) continue ;
            if(val+Val[j]<=Nkl)
            {
                val+=Val[j]; vis[j]=1;
                int k=j-1;
                while(vis[k]) k--;
                vis[k]=1;
                break ;
            }
        }
        if(val==Val[i])
        {
            int k=i-1;
            while(vis[k]) k--;
            val+=Val[k]; vis[k]=1;
            k=k-1;
            while(vis[k]) k--; vis[k]=1;
        }
        Ans[++cnt]=val;
    }
    sort(Ans+1,Ans+1+cnt,cmp2);
    for(int i=1;i<=cnt;i++)
    {
        if(Ans[i]==Nkl) 
        {
            printf("%d",i); break ;
        }
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}