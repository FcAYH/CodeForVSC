// WXR002.cpp: 主项目文件。

//#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>

struct CNode
{
	int m_a;
	int m_b;
};

int  CountOfResult(int a, int b)
{
	int i,j;
	int cnt = 0;

	for (i = b; i*i <= a; i++)
	if ((a % i)==0)
	{
		j = a / i;
		if (j >= b) cnt++;
	}
	return cnt;
}

int main()
{
//    Console::WriteLine(L"Hello World");
	//printf("Enter T:");
	int i,T;
	scanf("%d", &T);
	CNode * p = (CNode *)malloc(sizeof(p[0])*T);
	for (i = 0; i < T; i++)
	{
		//printf("Enter %d a b:", i);
		scanf("%d%d", &p[i].m_a, &p[i].m_b);
	}
	for (i = 0; i < T; i++)
	{
		int c = CountOfResult(p[i].m_a, p[i].m_b);
		printf("Case %d:%d\n", i+1, c);
	}
	free(p);
	return 0;
}
