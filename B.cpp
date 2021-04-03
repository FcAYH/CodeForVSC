#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	while(1)
	{
		double a,b,c;
		scanf("%lf%lf%lf",&a,&b,&c);
		a=min(a,50.0),b=min(b,50.0),c=min(c,50.0);
		if(a==0&&b==0&&c==0)	break;
		if(b<5.0)
		{
			printf("L 45\n");
			continue;
		}
		if(a<5.0)
		{
			printf("R 30\n");
			continue;
		}
		if(c<5.0)
		{
			printf("L 30\n");
			continue;
		}
		if(a-c>20.0)
		{
			printf("L 15\n");
			continue;
		}
		if(c-a>20.0)
		{
			printf("R 15\n");
			continue;
		}
		printf("S 0\n");
	}	
	return 0;
}