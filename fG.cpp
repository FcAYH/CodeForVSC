#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int Maxn=1000010;
int t;
char a[Maxn],b[Maxn];
void Solve()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a)),memset(b,0,sizeof(b));
        scanf("%s",a+1),scanf("%s",b+1);
        int len1=strlen(a+1),len2=strlen(b+1),cnt=0;
        int ans=(a[1]-'0')^(b[1]-'0');
        for(int i=2;i<=len2;i++) ans^=(a[i]-'0')^(b[i]-'0');
        if(!ans) cnt++;
        for(int i=len2+1;i<=len1;i++)
        {
            ans^=(a[i-len2]-'0')^(a[i]-'0');
            if(!ans) cnt++;
        }
        printf("%d\n",cnt);
    }
}
int main()
{
    Solve();
    return 0;
}
