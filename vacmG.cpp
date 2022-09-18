#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int ah[9],ssm,cnt,gm;
int main()
{	
	for(int i=0;i<=9;i++) scanf("%d",&ah[i]);
	scanf("%d",&ssm);
	gm=ssm+30;
	cnt=0;
	for(int i=0;i<=9;i++) if(ah[i]<=gm) cnt++;
	printf("%d",cnt);
    //system("pause");
	return 0;
}