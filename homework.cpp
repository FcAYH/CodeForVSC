#include<stdio.h>

int main(void)

{
	int year,month;
	printf("请输入年和月（用空格分隔）：\n");
	scanf("%d,%d",&year,&month);
	switch (month)
	{
	case 2:
		if (year%400==0)
		printf("29天！\n");
		else
		printf("28天！\n");
		break;
	case 4:
    case 6:
	case 9:
	case 11:
		printf("30天！\n");
		break;
	default:
		printf("31天！\n");
		break;
	}
	return 0;
}