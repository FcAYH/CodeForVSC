#include<stdio.h>

int Check(int x)
{
    int sum=0;
    for(int i=1;i<x;i++) if(!(x%i)) sum+=i;
    return (sum==x);
}

int main()
{
    int n;
    printf("Input m:\n");
    scanf("%d",&n);
    
    (Check(n))?printf("%d is a perfect number\n",n):printf("%d is not a perfect number\n",n);
    
    while(1);
    return 0;
}