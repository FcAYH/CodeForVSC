#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793238462643;
double a,b,c,r;

void Solve()
{
    scanf("%lf%lf%lf%lf",&a,&b,&c,&r);
    double p=(a+b+c)/2;
    double S=sqrt(p*(p-a)*(p-b)*(p-c));
    

    double Arc1=acos((b*b+c*c-a*a)/(2*b*c));
        double Arc1_=Arc1/2;
        double l1=r/tan(Arc1_);
        double S1=r*l1-((pi-2*Arc1_)/2)*r*r;

    double Arc2=acos((a*a+c*c-b*b)/(2*a*c));
        double Arc2_=Arc2/2;
        double l2=r/tan(Arc2_);
        double S2=r*l2-((pi-2*Arc2_)/2)*r*r;

    double Arc3=acos((a*a+b*b-c*c)/(2*a*b));
        double Arc3_=Arc3/2;
        double l3=r/tan(Arc3_);
        double S3=r*l3-((pi-2*Arc3_)/2)*r*r;

    double ans=(S-S1-S2-S3)/S;
    printf("%.15lf",ans);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
//3.14159265358979323846264338327950288419716939937510