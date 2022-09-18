// WXR001.cpp: 主项目文件。

//#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>

#include <iostream>

//---------------------------------------------------------------------------------
// 颜色序列
//---------------------------------------------------------------------------------
struct CVector
{
	CVector * m_NextInList;						// 在历史列表中的后继指针
	CVector * m_FatherInTree;					// 在搜索树中的父亲指针
	int       m_Step;							//
	int       m_SwapPos;						// 交换的下标,把 m_SwapPos 与 m_SwapPos+1 交换
	int       m_Count;							// 颜色个数
	int       m_ColorArray[1];					// 各颜色值
};

//---------------------------------------------------------------------------------
// 创建一个向量结点
//---------------------------------------------------------------------------------
CVector * GenerateVector(int n, int pColor[])
{
	int i;

	CVector * p = (CVector *)malloc(sizeof(p[0])+n*sizeof(int));
	p->m_Count = n;								// 颜色个数
	p->m_NextInList = NULL;						// 在历史列表中的后继指针
	p->m_FatherInTree = NULL;					// 在搜索树中的父亲指针
	p->m_SwapPos = -1;							// 交换的下标,把 m_SwapPos 与 m_SwapPos+1 交换
	p->m_Step = 0;

	for (i = 0; i < n; i++)
	{
		p->m_ColorArray[i] = (pColor==NULL) ? 0 : pColor[i];			// 各颜色值
	}
	return p;
}

//---------------------------------------------------------------------------------
// 在结点 p 中交换 IndexOfSwap 和 IndexOfSwap+1 两个元素
//---------------------------------------------------------------------------------
int SwapToColors(CVector * p, int IndexOfSwap)
{
	p->m_SwapPos = IndexOfSwap;					// 交换的下标,把 m_SwapPos 与 m_SwapPos+1 交换
	int x = p->m_ColorArray[IndexOfSwap];
	p->m_ColorArray[IndexOfSwap] = p->m_ColorArray[IndexOfSwap + 1];
	p->m_ColorArray[IndexOfSwap + 1] = x;
	return 0;
}

int AssignColors(CVector * p, int pColor[])
{
	int i;

	for (i = 0; i < p->m_Count; i++)
	{
		p->m_ColorArray[i] = (pColor == NULL) ? 0 : pColor[i];			// 各颜色值
	}
	return 0;
}

//---------------------------------------------------------------------------------
// 判断一个颜色序列是否"成块"完毕
// 返回 1 是,已成块
// 返回 0 否,没有成块
//---------------------------------------------------------------------------------
int IsVectorBlocked(int n,int pColor[])
{
	int i,j;

	for (i=1;i<n;i++)							// 从 [1] 开始检查
	if (pColor[i] != pColor[i - 1])				// 发现两块接头
	{
		for (j = 0; j < i; j++)
		if (pColor[j] == pColor[i]) return 0;	// 发现重复的块,返回 0
	}
	return 1;									// 返回 1 表示已成块
}

//---------------------------------------------------------------------------------
// 判断2个颜色序列是否相同
// 返回 1 相同
// 返回 0 不相同
//---------------------------------------------------------------------------------
int IsVectorSame(int n, int pColor1[], int pColor2[])
{
	int i;

	for (i = 0; i < n; i++)
		if (pColor1[i] != pColor2[i]) return 0;
	return 1;
}

int IsThisColorVectorInList(CVector * pList, int pColor[])
{
	while (pList)
	{
		if (IsVectorSame(pList->m_Count, pList->m_ColorArray, pColor)) return 1;
		pList = pList->m_NextInList;
	}
	return 0;
}

int OutputSwapTrace(CVector * p)
{
	int i;

	if (p->m_FatherInTree)
	{
		OutputSwapTrace(p->m_FatherInTree);
	}
	if (p->m_SwapPos < 0)
	{
		printf("Start from ==>");
	}
	else
	{
		printf("Swap %d,%d ==>", p->m_SwapPos, p->m_SwapPos + 1);
	}
	for (i = 0; i < p->m_Count; i++) printf(" %d", p->m_ColorArray[i]);
	printf("\n");
	return 0;
}

int main(int argn, char * argv)
{
	int i,n;

	printf("Enter Count Of Leaves:");
	scanf("%d", &n);
	if (n < 1)
	{
		printf("Invalid number:%d\n", n);
		return 0;
	}
	CVector * pRoot = GenerateVector(n, NULL);
	for (i = 0; i < n; i++)
	{
		printf("Enter Color of  Leaf[%d]:", i);
		scanf("%d", &pRoot->m_ColorArray[i]);
	}
	if (IsVectorBlocked(pRoot->m_Count, pRoot->m_ColorArray))
	{
		printf("Already Blocked. Need 0 step\n");
	}
	else
	{
		CVector * pLast = pRoot;							// 末结点,新增结点加在它后面
		CVector * pNode = pRoot;							// 当前结点,由它产生后继结点
		CVector * q=NULL;									// 中间结点,开始为空
		CVector * pFinalNode = NULL;						// 终止结点,开始为空

		while (pNode != NULL && pFinalNode==NULL)			// 当前结点不空,且没有发现终止结点
		{
			for (i=1;i<n;i++)								// 查找块间连接处
			if (pNode->m_ColorArray[i - 1] != pNode->m_ColorArray[i])
			{
				if (q == NULL) q = GenerateVector(n, pNode->m_ColorArray);
				else AssignColors(q, pNode->m_ColorArray);

				SwapToColors(q, i - 1);
				if (IsThisColorVectorInList(pRoot, q->m_ColorArray) == 0)
				{
					q->m_Step = pNode->m_Step + 1;
					pLast->m_NextInList = q;				// 把 q 加入总列表
					pLast = q;
					q->m_FatherInTree = pNode;				// 记录父结点
					q = NULL;
					if (IsVectorBlocked(n, pLast->m_ColorArray))
					{
						pFinalNode = pLast;
						break;
					}
				}
			}
			pNode = pNode->m_NextInList;
		}
		printf("Need %d steps\n", pFinalNode->m_Step);
		OutputSwapTrace(pFinalNode);
		if (q) free(q);
		pNode = pRoot;							// 当前结点,由它产生后继结点
		while (pNode)
		{
			q = pNode->m_NextInList;
			free(pNode);
			pNode = q;
		}
	}
//	for (i = 0; i < n; i++) printf(" %d", pRoot->m_ColorArray[i]);
system("pause");
	return 0;
}
