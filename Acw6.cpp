#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=20005;
struct Queue{int val,cnt;}Q[Maxn];
int n,V;
int v,w,s;
int A[2][20005];

void Solve()
{
    scanf("%d%d",&n,&V);
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&v,&w,&s);
        for(int j=0;j<v;j++)
        {
            int head=1,tail=0;
            for(int k=0;k<=(V-j)/v;k++)
            {
                int Val=A[flag^1][j+k*v]-k*w;
                while(head<=tail&&Q[tail].val<Val) tail--;
                Q[++tail].val=Val,Q[tail].cnt=k;
                while(head<=tail&&k-Q[head].cnt>s) head++;
                A[flag][j+k*v]=Q[head].val+k*w;
            }
        }
        flag^=1;
    }
    printf("%d\n",A[flag^1][V]);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}