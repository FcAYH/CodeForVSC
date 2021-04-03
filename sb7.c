#include<stdio.h>
#include<math.h>

int n;
int cnt=0;

inline int IsPrime(double x)
{
    for(double i=2;i<=sqrt(x);i+=1.0)
    {
        if(x/i == (long long)(x/i)) 
        {
            //printf("%lf %lld \n",x/i,(long long)(x/i));
            return 0;
        }
    }
    return 1;
}

inline void Calc(int x)
{
    double a=2.0;
    for(int i=2;i<=x;i++) a=a*2; 
    if(IsPrime(a-1)) printf("2^%d-1=%.0lf\n",x,a-1),cnt++;
}

int main()
{
    printf("Input n:\n");
    scanf("%d",&n);
    for(int i=2;i<=n;i++) Calc(i);
    printf("count=%d\n",cnt);
    
    while(1);


    return 0;
}
