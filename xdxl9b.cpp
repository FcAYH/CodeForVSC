#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve()
{
    int T;
    scanf("%d",&T);
    double r,xp,yp,xq,yq;
    while(T--)
    {
        scanf("%lf",&r);
        scanf("%lf%lf%lf%lf",&xp,&yp,&xq,&yq);
        double COS=(xp*xq+yp*yq)/(sqrt(xp*xp+yp*yp)*sqrt(xq*xq+yq*yq));
        printf("<%lf> ",COS);
        double a=(sqrt(xp*xp+yp*yp)),b=2*r-sqrt(xq*xq+yq*yq);
        printf("<%lf %lf> ",a,b);
        double LEN=sqrt(a*a+b*b);
        printf("%.7lf\n",LEN);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}