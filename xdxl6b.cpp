#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=100;
int t,n,m;
char s1[Maxn];
char s2[Maxn];
char s3[Maxn];
void Solve()
{
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {

        scanf("%d%d",&n,&m);
        scanf("%s",s1+1);
        scanf("%s",s2+1);
        scanf("%s",s3+1);
        printf("Case #%d: ",i);
        for(int j=1;j<=m;j++) 
        {
            if(s3[j]-(s2[1]-s1[1])<'A') printf("%c",s3[j]-(s2[1]-s1[1])+26);
            else if(s3[j]-(s2[1]-s1[1])>'Z') printf("%c",s3[j]-(s2[1]-s1[1])-26);
            else printf("%c",s3[j]-(s2[1]-s1[1]));
        }
        puts("");
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
1
7 7
CCCCCCC
AAAAAAA
BBBBBBB
*/