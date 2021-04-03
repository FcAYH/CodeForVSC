#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=200;
string s[Maxn];
void Solve()
{
    char ch;int n;
    scanf("%c%d",&ch,&n);
    getchar();
    for(int i=1;i<=n;i++) getline(cin,s[i]);
    int flag=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n-1;j++) if(s[i][j]!=s[n-i+1][n-j-1]) flag=0;
    }
    if(flag) printf("bu yong dao le\n");
    for(int i=n;i>=1;i--)
    {
        for(int j=n-1;j>=0;j--) if(s[i][j]!=' ') printf("%c",ch); else printf(" ");
        puts("");
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}