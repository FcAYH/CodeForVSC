#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int T,n;
int a,b,c,ab,ac,bc,abc;
int A,B,C,AB,AC,BC,ABC;
void Solve()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d%d%d%d%d",&a,&b,&c,&ab,&bc,&ac,&abc);
            ABC=abc;
            AB=ab-ABC,AC=ac-ABC,BC=bc-ABC;
            A=a-AB-AC-ABC,B=b-AB-BC-ABC,C=c-AC-BC-ABC;
            if(A<0||B<0||C<0||AB<0||AC<0||BC<0||ABC<0) continue ; 
            ans=max(ans,A+B+C+AB+AC+BC+ABC); 
        }
        printf("%d\n",ans);
    }
   
}
int main()
{
    Solve();
    system("pause");
    return 0;
}