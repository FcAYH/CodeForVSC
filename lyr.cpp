#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#define N 20
int a[N+1];
int main()
{
    int cnt1=0,cnt2=0;
    srand(time(0));
    for(int i=1;i<=1000000;i++)
    {
        int x=rand()%2;
        (x==1)?cnt1++:cnt2++;
    }
    printf("%d %d\n",cnt1,cnt2);
    system("pause");
    return 0;
}
