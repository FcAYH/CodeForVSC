#include<bits/stdc++.h>
using namespace std;
const int Maxn=20;
int N;
struct Preson
{
    char name[30]; int bre,be;
}Per[Maxn];
void Solve()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%s%d%d",Per[i].name,&Per[i].bre,&Per[i].be);
    for(int i=1;i<=N;i++)
    {
        if(Per[i].bre>=15&&Per[i].bre<=20&&Per[i].be>=50&&Per[i].be<=70) continue ;
        printf("%s\n",Per[i].name);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}