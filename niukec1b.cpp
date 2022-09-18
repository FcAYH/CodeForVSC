#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Inf=0x3f3f3f3f;
const int Maxn=30;
char s[Maxn];
int Ans[Maxn];
void Solve()
{
    cin>>(s+1);
    int len=strlen(s+1);
    memset(Ans,0x3f,sizeof(Ans));
    Ans[1]=0;
    for(int i=2;i<=len;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(s[i]=='R')
            {
                if(s[j]=='B')  Ans[i]=min(Ans[i],Ans[j]+(i-j)*(i-j));
            }
            else if(s[i]=='G')
            {
                if(s[j]=='R')  Ans[i]=min(Ans[i],Ans[j]+(i-j)*(i-j));
            }
            else
            {
                if(s[j]=='G')  Ans[i]=min(Ans[i],Ans[j]+(i-j)*(i-j));
            }
        }
    }
    if(Ans[len]==Inf) printf("-1");
    else printf("%d",Ans[len]);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}