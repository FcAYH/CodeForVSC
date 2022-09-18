#include<stdio.h>

int wmin(int x,int y)
{
    return (x<y)?x:y;
}

int wmax(int x,int y)
{
    return (x>y)?x:y;
}

int maxProfit(int prices[], int n)
{
    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(prices[i]>prices[i-1]) ans+=prices[i]-prices[i-1];
    }
    return ans;
}

int main()
{
    int  n;
    int  array[128];
    printf("Please input the array size\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Please input the %d-th number\n",i);
        scanf("%d",&array[i]);
    }
    int pMax=maxProfit(array,n);
    printf("the maxProfit is %d\n",pMax);

    while(1);
    return 0;
}