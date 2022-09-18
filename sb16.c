#include<stdio.h>
#include<math.h>

int Cnt[10];

int Solve(int x)
{
    int Bits=0;
    while(x) Cnt[x%10]++,x/=10,Bits++;
    return Bits;
}

int main()
{
    int n;
    printf("Please enter the number:\n");
    scanf("%d",&n);
    
    int Bits=Solve(abs(n));

    printf("%d: %d bits\n",n,Bits);
    
    for(int i=0;i<=9;i++) if(Cnt[i]) printf("%d: %d\n",i,Cnt[i]);
    
    while(1);

    return 0;
}