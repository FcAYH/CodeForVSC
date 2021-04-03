#include<stdio.h>
#include<math.h>

int n,cnt=0;

int Check(int x)
{
    for(int i=2;i<=sqrt(x);i++) if(!(x%i)) return 0;
    if(x<100)
    {
        if(x%10==x/10) return 1;
    }
    else if(x<1000)
    {
        if(x%10==x/100) return 1;
    }
    else
    {
        if(x%10==x/1000&&x/10%10==x/100%10) return 1;
    }
    return 0;
    
}

int main()
{
    printf("Input n:\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++) if(Check(i)) printf("%4d",i),cnt++;
    printf("\ncount=%d\n",cnt);
    while(1);
    return 0;
}