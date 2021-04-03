#include<stdio.h>

int Calc(int x)
{
    int ret=0;
    for(int i=1;i<=x;i++) ret=ret*10+x;
    return ret;
}

int main()
{
    int n;
    printf("please input how many terms you want to compute?:\n");
    scanf("%d",&n);
    if(n<1||n>=10) printf("Overflow!\n");
    else
    {
        int sum=0;
        for(int i=1;i<=n;i++) sum+=Calc(i);
        printf("sum=%ld\n",sum);
    }
    

    while(1);
    return 0;
}