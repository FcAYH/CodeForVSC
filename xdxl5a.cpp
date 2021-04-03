#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=1000001;
int n,k,num;
int vis[Maxn];
void Solve()
{
    scanf("%d%d",&n,&k);
    int cnt=0,ans=0;
    for(int i=1;i<=k;i++) 
    {
        scanf("%d",&num);
        for(int j=num;j<=n;j+=num)
        {
            if(vis[j]) vis[j]=0,cnt--;
            else  vis[j]=1,cnt++;
        }
        ans=max(ans,cnt);
    }
    printf("%d",ans);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}