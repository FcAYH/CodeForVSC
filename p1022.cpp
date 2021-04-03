#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=100001;
char s[Maxn];
char Unknow;
void Solve()
{
    cin>>(s+1);
    int len=strlen(s+1);
    int i=1;
    int same=1,flag=1,num=0,x=0;
    for(int i=1;i<=len;i++) if(s[i]>='a'&&s[i]<='z') Unknow=s[i];
    while(s[i]!='=')
    {
        int nown=0;
        while(s[i]!='+'&&s[i]!='-'&&s[i]>='0'&&s[i]<='9') nown=nown*10+s[i]-'0',i++;
        if(s[i]>='a'&&s[i]<='z') 
        {
            if(!nown) nown=1;
            x+=same*flag*nown,i++;
        }
        else 
        {
            num+=same*flag*nown;
            if(s[i]=='=') break ; 
            if(s[i]=='+') flag=1;
            if(s[i]=='-') flag=-1;
            i++;
        }
    }
    same=-1,flag=1;
    i++;
    while(i<=len)
    {
        int nown=0;
        while(s[i]!='+'&&s[i]!='-'&&s[i]>='0'&&s[i]<='9') nown=nown*10+s[i]-'0',i++;
        if(s[i]>='a'&&s[i]<='z') 
        {
            if(!nown) nown=1;
            x+=same*flag*nown,i++;
        }
        else 
        {
            num+=same*flag*nown;
            if(s[i]=='=') break ; 
            if(s[i]=='+') flag=1;
            if(s[i]=='-') flag=-1;
            i++;
        }
    }
    double ans=-(double)(num)/(double)x;
    printf("%c=%.3lf",Unknow,ans);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
6a-5+1=2-2a

4+3x=8

6a−5+1=2−2a

−5+12y=0

6a-5+1=2-2a
*/