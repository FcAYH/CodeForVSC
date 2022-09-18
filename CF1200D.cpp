#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Ini_()
{
    for(int i=1;i<=n;i++)
    {
        int Nowp=1;
        while(Map[i][Nowp]=='W') Nowp++;        
        LineL[i]=Nowp;
        Nowp=n;
        while(Map[i][Nowp]=='W') Nowp--;
        LineR[i]=Nowp;
    }
    for(int i=1;i<=n;i++)
    {
        int Nowp=1;
        while(Map[Nowp][i]=='W') Nowp++;        
        RowU[i]=Nowp;
        Nowp=n;
        while(Map[Nowp][i]=='W') Nowp--;
        RowB[i]=Nowp;
    }
}
void Solve()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%s",Map[i]+1);
    Ini_();
}
int main()
{
    Solve();
    system("pause");
    return 0;
}