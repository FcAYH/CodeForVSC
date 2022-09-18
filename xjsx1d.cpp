#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int Maxn=1000100;
char s1[Maxn];
char s2[Maxn];
void Solve()
{
    cin>>s1>>s2;
    int len1=strlen(s1);
    int len2=strlen(s2);
    int Node=0;
    for(int i=0;i<len1;i++)
    {
        if(s1[i]==s2[Node]) Node++;
        if(Node==len2)
        {
            printf("YES"); return ;
        }
    }
    printf("NO");
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
threeyellowfurryfiend
hellofriend
*/