#include<stdio.h>
#include<math.h>

int main()
{
    int a,b;

    printf("请输入两个整数：");
    scanf("%d%d",&a,&b);
    printf("%d is %.1f percent of %d",a,(float)(a)/(float)(b)*100,b);

    while(1);

    return 0;
}