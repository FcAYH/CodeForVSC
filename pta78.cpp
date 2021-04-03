#include<bits/stdc++.h>
using namespace std;
const int Maxn=20000;
int n;
char ch;
string s;
void Solve()
{
    scanf("%d",&n);
    getchar();
    scanf("%c",&ch);
    getchar();
    getline(cin,s);
    int len=s.length();
    if(n>len) 
    {
        for(int i=1;i<=n-len;i++) printf("%c",ch);
        cout<<s;
    }
    else
    {
        for(int i=len-n;i<len;i++) putchar(s[i]);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}