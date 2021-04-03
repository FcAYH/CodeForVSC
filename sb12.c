#include<stdio.h>
#include<math.h>

#define e 2.7182818284
int main()
{
    printf("Please input x:\n");
    float x,y;
    scanf("%f",&x);
    if(x<0.0) y=3.0*x-1.0;
    else if(x>=0.0&&x<10.0) y=exp(x);
    else y=x;
    printf("y = %.2f\n",y);
    while(1);
    return 0;
}
