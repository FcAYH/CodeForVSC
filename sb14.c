#include<stdio.h>

void bubble(int [], int);
#define LEN 10                     //zcfu
main( )
{
	int  data[LEN], i;              //zcfu
	for (i=0; i<= LEN-1; i++)
		scanf("%d", &data[i]);       //zcfu
	printf("\n");

    bubble(data, LEN);   //zcfu 

	for(i=0; i< LEN; i++) 	// Output
		printf("%8d", data[i]);
}

void bubble(int dat[], int length)
{
    int head, tail,round,i;
    int t;

    head = 0;
    tail = length - 1;

	for (round = head; round <= tail; round++)
		for (i = tail; i >= round+1; i--)
			if ( dat[i] < dat[i-1] )	{
				t=dat[i];             //zcfu
				dat[i]=dat[i-1];
				dat[i-1]=t;
			}

}