#include<stdio.h>

int Day1[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int Day2[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

int  DayofYear(int year, int month, int day)
{
    int yearDay=0;
    if((!(year%4)&&(year%100))||(!(year%400)))
    {
        for(int i=1;i<month;i++) yearDay+=Day2[i];
    }
    else
    {
        for(int i=1;i<month;i++) yearDay+=Day1[i];
    }

    printf("yearDay = %d\n",yearDay+day);
}

void  MonthDay(int year, int yearDay, int *pMonth, int *pDay)
{
    if((!(year%4)&&(year%100))||(!(year%400)))
    {
        int i=1;
        while(yearDay>=Day2[i]) yearDay-=Day2[i],i++;
        *pMonth=i;
        *pDay=yearDay;
    }
    else
    {
        int i=1;
        while(yearDay>=Day1[i]) yearDay-=Day1[i],i++;
        *pMonth=i;
        *pDay=yearDay;
    }

}

int main()
{
    int choice;
    printf("1. year/month/day -> yearDay\n2. yearDay -> year/month/day\n3. Exit\nPlease enter your choice:");
    scanf("%d",&choice);
    
    int year,month,day,yearday,pMonth,pDay;

    switch (choice)
    {
        case 1:
            printf("Please enter year, month, day:");
            scanf("%d,%d,%d",&year,&month,&day);
            DayofYear(year,month,day);
        break ;

        case 2:
            printf("Please enter year, yearDay:");
            scanf("%d,%d",&year,&yearday);
            MonthDay(year,yearday,&pMonth,&pDay);
            printf("month = %d,day = %d\n",pMonth,pDay);
        break ;

        default:

        break ;
    }

    while(1);
}