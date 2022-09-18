#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void bfs()
{
    queue<int> qx,qy,qk;
    qx.push(1),qy.push(1),qk.push(k);
    while(!qx.empty())
    {
        int nowx=qx.front(),nowy=qy.front(),nowk=qk.front();
        qx.pop(),qy.pop(),qk.pop();
        
    }
}
void Solve()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%s",Map[i]+1);
    bfs();
}
int main()
{
    Solve();
    system("pause");
    return 0;
}