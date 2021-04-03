#include<bits/stdc++.h>
using namespace std;
int ans1=0,ans2=0;
int R,B,C,D,E;
void Solve()
{
    scanf("%d%d%d%d%d",&R,&B,&C,&D,&E);
    //red to red
    ans1=R*C+B*D;
    //red to blue
    if(R<=B) ans2=R*E+(B-R)*D+R*E;
    else ans2=B*E+(R-B)*C+B*E;
    printf("%d\n",max(ans1,ans2));
}
int main()
{
    Solve();
    system("pause");
    return 0;
}