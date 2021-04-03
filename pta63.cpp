
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int Maxn=11;
int year,dif;
int vis[Maxn];
int main()
{
    scanf("%d%d",&year,&dif);
    int Cye=year,county=0;
    while(++county)
    {
        int iC=Cye+county-1;
        memset(vis,0,sizeof(vis)); 
        int cnt=0,cntw=0;
        while(iC) vis[iC%10]=1,iC/=10,cntw++;
        if(cntw<4) vis[0]++;
        for(int i=0;i<=9;i++) if(vis[i]) cnt++;
        if(cnt==dif)
        {
            printf("%d ",county-1);
            if(year+county-1<10) printf("000%d",year+county-1);
            else if(year+county-1>=10&&year+county-1<100) printf("00%d",year+county-1);
            else if(year+county-1>=100&&year+county-1<1000) printf("0%d",year+county-1);
            else printf("%d",year+county-1);
            break ;
        }
    }
    system("pause");
    return 0;   
}