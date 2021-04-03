#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int Check(int x)
{
    if(x==1) return 0;
    else if(!(x%2)) return Check(x/2);
    else if(!(x%5)) return Check(x/5);
    return 1;
}
void Solve()
{
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        (Check(n))?printf("Yes\n"):printf("No\n");
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}