#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n;
int ans=0;
char id[20];
int heav[20]={0,7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char pla[20]={'1','0','X','9','8','7','6','5','4','3','2'};
void Solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        ans=0;
        cin>>(id+1);
        for(int i=1;i<=17;i++) ans+=(id[i]-'0')*heav[i];
        int Div=ans%11;
        //printf("%c ",id[18],pla[Div])
        if(id[18]==pla[Div]) printf("True\n");
        else printf("False\n");
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
2
53010219200508011X
370902200107092438
*/