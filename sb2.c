#include<stdio.h>
#include<math.h>

int Users[25];

int main()
{
    int sum=0,uMax=0,uMin=0x3f3f3f3f,uMax_T=0,uMin_T=0;

    for(int i=0;i<=23;i++)
    {
        printf("请输入在%d:00和%d:00之间登录的用户数：",i,i+1);
        scanf("%d",&Users[i]); sum+=Users[i];
        if(Users[i]>uMax) uMax=Users[i],uMax_T=i; 
        if(Users[i]<uMin) uMin=Users[i],uMin_T=i; 
    }

    //printf("%d\n",sum);

    printf("   时间                 登录人数                 所占比例\n");
    for(int i=0;i<=23;i++)
    {
        printf("%2d:00 - %2d:00 %15d %25.1f\n",i,i+1,Users[i],(float)(Users[i])/(float)(sum)*100.0);
    }
    printf("最大登录人数%d发生在%2d：00到%2d：00之间\n",uMax,uMax_T,uMax_T+1);
    printf("最小登录人数%d发生在%2d：00到%2d：00之间\n",uMin,uMin_T,uMin_T+1);
    while(1);

    return 0;
}