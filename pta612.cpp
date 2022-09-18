#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int P1,P2;
int a[4];
int PwP[3];
int main()
{
    scanf("%d%d",&P1,&P2);
    scanf("%d%d%d",&a[1],&a[2],&a[3]);
    for(int i=1;i<=3;i++) PwP[a[i]]++;
    if(P1>P2) if(PwP[0]>=1) printf("The winner is a: %d + %d",P1,PwP[0]);
    if(P2>P1) if(PwP[1]>=1) printf("The winner is b: %d + %d",P2,PwP[1]);
    if(P1<P2) if(PwP[0]==3) printf("The winner is a: %d + %d",P1,PwP[0]);
    if(P2<P1) if(PwP[1]==3) printf("The winner is b: %d + %d",P2,PwP[1]);
    system("pause");
    return 0;
}