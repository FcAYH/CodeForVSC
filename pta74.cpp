#include<bits/stdc++.h>
using namespace std;
int k;
char compete[20];
void Solve()
{
    scanf("%d",&k);
    int cnt=0;
    while(scanf("%s",compete))
    {
        if(compete[0]=='E') break ;
        cnt++;
        if(!(cnt%(k+1))) cnt=0,printf("%s\n",compete);
        else if(compete[0]=='C') printf("Bu\n");
        else if(compete[0]=='B') printf("JianDao\n");
        else if(compete[0]=='J') printf("ChuiZi\n");
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}