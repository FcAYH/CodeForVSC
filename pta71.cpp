#include<bits/stdc++.h>
using namespace std;
int x,cnt=0;
void Solve()
{
    while(scanf("%d",&x))
    {
        cnt++;
        if(x==250) break ;
    }
    printf("%d",cnt);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}