#include<stdio.h>

int main()
{
    short int a,b,c,d;
    
    scanf("a = %3hd%4hd, b = %3hd%4hd",&a,&b,&c,&d);//printf("ss");
    printf("a + b = %d",(int)a*10000+(int)b+(int)c*10000+(int)d);
    while(1);
    return 0;
}
//a = 1234567, b = 7654321