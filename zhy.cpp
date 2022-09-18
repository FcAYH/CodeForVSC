/*#include<cstdio>
int main()
{
	int n=2,k=0;
	while(k++&&n++>2);
	printf("%d %d\n",k,n);
	while(1);
}
*/
/*
*/
#include<cstdio>
int main()
{
	int c=0,k;
	for(k=1;k<3;k++)
	{
		switch(k)
		{
			default: c+=k;
			case 2: c++; break ;
			case 4: c+=2; break ; 
		}
	}
	printf("%d",c);
	double p=4.9;
	printf("%d\n",(int)p);
	while(1);
}