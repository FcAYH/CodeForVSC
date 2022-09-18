#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
double weight,hight;
int main()
{
    scanf("%lf%lf",&weight,&hight);
    printf("%.1lf\n",weight/(hight*hight));
    if(weight/(hight*hight)>25) printf("PANG");
    else printf("Hai Xing");
    system("pause");
    return 0;
}