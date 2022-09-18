#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=1000100;
int n;
char s[Maxn];
int Pre[Maxn];
int Pre_rev[Maxn];
void Work()
{
    int ans=0;
    if(Pre[n]==2)
    {
        for(int i=n;i>=1;i--) 
        {
            if(Pre[i]<2) break ; 
            if(Pre[i]>=2&&s[i]=='(') ans++;
        }
    }
    if(Pre[n]==-2)
    {
        for(int i=1;i<=n;i++) 
        {
            if(Pre_rev[i]>-2) break ;
            if(Pre_rev[i]<=-2&&s[i]==')') ans++;
        }
    }
    printf("%d",ans);
}
void Solve()
{
    scanf("%d",&n);
    cin>>(s+1);
    Pre[0]=0,Pre_rev[n+1]=0;
    for(int i=1;i<=n;i++) (s[i]=='(')?Pre[i]=Pre[i-1]+1:Pre[i]=Pre[i-1]-1;
    for(int i=n;i>=1;i--) (s[i]=='(')?Pre_rev[i]=Pre_rev[i+1]+1:Pre_rev[i]=Pre_rev[i+1]-1;
    if(Pre[n]!=2&&Pre[n]!=-2) printf("0");
    else 
    {
        int flag=0;
        if(Pre[n]==2) for(int i=1;i<=n;i++) if(Pre[i]<0) flag=1;
        if(Pre[n]==-2) for(int i=n;i>=1;i--) if(Pre_rev[i]>0) flag=1;
        if(flag) printf("0");else Work();
    } 
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
8
(()((())
*/