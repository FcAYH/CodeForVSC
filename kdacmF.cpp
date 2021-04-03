#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    printf("%.1lf\n",sqrt((a-c)*(a-c)+(b-d)*(b-d)));
    return 0;
}