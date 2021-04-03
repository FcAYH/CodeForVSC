#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Maxn=1000;
char s[Maxn];
void Solve()
{
    cin>>(s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;i++)
    {
        if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'&&s[i]!='n')
        {
            if(s[i+1]=='a'||s[i+1]=='e'||s[i+1]=='i'||s[i+1]=='o'||s[i+1]=='u') continue ;
            else
            {
                printf("NO"); return ;
            }
        }
    }
    printf("YES");
}
int main()
{
    Solve();
    system("pause");
    return 0;
}