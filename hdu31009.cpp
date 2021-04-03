#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=100100;
int t;
char s[Maxn];
int Pre[Maxn];
int PreX[Maxn];
int Suf[Maxn];
int SufX[Maxn];
void Solve()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s+1);
        int len=strlen(s+1);
        Pre[0]=0,PreX[0]=0,Suf[len+1]=0,SufX[len+1]=0;
        for(int i=1;i<=len;i++) 
        {
            if(s[i]=='(') Pre[i]=Pre[i-1]+1;
            if(s[i]=='*') Pre[i]=Pre[i-1];
            if(s[i]==')') Pre[i]=Pre[i-1]-1;
        }
        for(int i=len;i>=1;i--) 
        {
            if(s[i]==')') Suf[i]=Suf[i+1]+1;
            if(s[i]=='(') Suf[i]=Suf[i+1]-1;
            if(s[i]=='*') Suf[i]=Suf[i+1];
        }

        for(int i=1;i<=len;i++) PreX[i]=(s[i]=='*')?PreX[i-1]+1:PreX[i-1];
        for(int i=len;i>=1;i--) SufX[i]=(s[i]=='*')?SufX[i+1]+1:SufX[i+1];

        int Tagp=0,Tags=0,flag=1;
        for(int i=1;i<=len;i++)
        {
            if(Pre[i]+Tagp<0)
            {
                if(PreX[i]+Pre[i]<0){flag=0; break ;}
                else Tagp++;
            }
        }
        if(!flag)
        {
            printf("No solution!\n"); continue ;
        }
        for(int i=len;i>=1;i--)
        {
            if(Suf[i]+Tags<0)
            {
                if(SufX[i]+Suf[i]<0){flag=0; break ;}
                else Tags++;
            }
        }
        if(!flag)
        {
            printf("No solution!\n"); continue ;
        }
        int cnt=0;
        //printf("<%d %d>\n",Tagp,Tags);
        for(int i=1;i<=len;i++)
        {
            if(cnt==Tagp) break ;
            if(s[i]=='*') s[i]='(',cnt++;
        }
        cnt=0;
        for(int i=len;i>=1;i--)
        {
            if(cnt==Tags) break ;
            if(s[i]=='*') s[i]=')',cnt++;
        }
        for(int i=1;i<=len;i++) if(s[i]!='*') putchar(s[i]);
        puts("");
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}