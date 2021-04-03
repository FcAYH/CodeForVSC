#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n;
char x[10];
int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) 
    {
        scanf("%s",x+1);
        int num1 = 0,num2 = 0;
        for(int j = 1; j <= 3; j++) num1+=x[j]-'0';
        for(int j = 4; j <= 6; j++) num2+=x[j]-'0';
        if(num1 == num2) printf("You are lucky!\n");
        else printf("Wish you good luck.\n");
    }
    system("pause");
    return 0;
}