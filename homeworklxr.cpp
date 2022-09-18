#include <stdio.h> 
#include<iostream>
int y,m,d;//����ȫ�ֱ��������� 
int gongneng1()//����1�ĺ��� 
{
	int d1,d2,d3,year,i,sum;
	d1=0,d2=0,d3=0,sum=0;
	int  a[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    
    while(1)
    {
        printf("����������:");
        scanf("%d.%d.%d",&y,&m,&d);
        if((y<1800)||(m>12||m<0)||(d>31||d<0)) printf("Invalid input\n");
        if((y%4==0&&y%100!=0)||y%400==0) break;
    } 
    if((y%4==0&&y%100!=0)||y%400==0)//�ж��Ƿ������� 
    {
        a[2]=29;
        year=366;
    }
    else
        year=365;
    d1=(y-1800)*year;
    for(i=1;i<m;i++)
    {
        d2+=a[i];
    }
    d3=d;
    sum=d1+d2+d3;//�����1800�굽���������ܹ������� 
    int x;
    x=sum%7;
    switch(x)// �жϸ��˵�������ʲô�� 
    {
        case 1:
        case 2:
        case 3:
        case 4:	printf("He is fishing\n");break;
        case 5:
        case 6: printf("He is sunshining net\n");break;
        case 0:	printf("He is breaking\n");break;
    }
    printf("\n");
    return x;
}
int main()
{
    gongneng1();
    std::system("pause");
    return 0;
}