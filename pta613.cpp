#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const double Inf=13948472383948293.0;
const int Maxn=20000;
int N;
struct Person{char name[20];double v;}P[Maxn]; 
int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%s%lf",P[i].name,&P[i].v);
    double val=0;
    for(int i=1;i<=N;i++) val+=P[i].v;
    val=(val/N)/2;
    double Min=Inf;
    int ans=0;
    for(int i=1;i<=N;i++) if(abs(P[i].v-val)<Min) ans=i,Min=abs(P[i].v-val);
    printf("%.0lf %s",floor(val),P[ans].name);
    system("pause");
    return 0;
}