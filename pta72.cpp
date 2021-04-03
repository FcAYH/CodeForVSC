#include<bits/stdc++.h>
using namespace std;
char s[15];
void Solve()
{
    scanf("%s",s+1);
    int len=strlen(s+1);
    for(int i=7;i<=len;i++) printf("%c",s[i]);
    printf("-");
    for(int i=1;i<=5;i++) printf("%c",s[i]);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}