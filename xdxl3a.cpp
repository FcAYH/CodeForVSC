#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a;
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Solve()
{
    while(scanf("%d",&n)!=EOF)
    {
        int flag=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            if(sqrt(a)*sqrt(a)!=a) flag=0; 
        }
        flag?printf("Yes\n"):printf("No\n");
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}