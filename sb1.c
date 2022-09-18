#include<stdio.h>
#include<math.h>

long long int a[100010];

int main()
{
    int n;
    scanf("%d",&n);
    int i=0;
    for(i=1;i<=n;i++)  scanf("%I64d",&a[i]); 
    for(i=1;i<=n;i++)
        (sqrt(a[i])*sqrt(a[i])==a[i])?printf("YES\n"):printf("NO\n");


    while(1);
    return 0;
}