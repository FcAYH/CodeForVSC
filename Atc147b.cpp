#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int Maxn=300;
char s[Maxn];
int ans=0;
void Solve()
{
    cin>>(s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len/2;i++) if(s[i]!=s[len-i+1]) ans++;
    printf("%d",ans);
}
int main()
{
    Solve();
    return 0;
}