#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct node{
	int data;
	node *next;
}LNode; 
LNode *A, *B;
//参数a与参数b分别是数组A和B的长度 
//传入地址符(引用)在函数中修改之后那么主程序中传进去的变量也会跟着改变 
void create(LNode *&A, LNode *&B, int arrA[], int a, int arrB[], int b){
	A = (LNode*)malloc(sizeof(LNode));
	B = (LNode*)malloc(sizeof(LNode));
	A->next = NULL;
	B->next = NULL;
	LNode *p = A;
	LNode *q = B;
	//创建链表A 
	for(int i = 0; i < a; ++i){
		LNode *newNode = (LNode*)malloc(sizeof(LNode));
		newNode->next = NULL;
		newNode->data = arrA[i];
		p->next = newNode;
		p = p->next; 
	}
	//创建链表B 
	for(int i = 0; i < b; ++i){
		LNode *newNode = (LNode*)malloc(sizeof(LNode));
		newNode->next = NULL;
		newNode->data = arrB[i];
		q->next = newNode;
		q = q->next; 
	}
}
 
void difference(LNode *&A, LNode *&B){
	LNode *p = A;
	LNode *q = B; 
	while(p->next != NULL && q->next != NULL){
		if(p->next->data == q->next->data){
			p->next = p->next->next;
			free(p);
		}else if(p->next->data > q->next->data){
			q = q->next;
		}else{
			p = p->next;	
		}
	} 
	LNode *s = A;
	while(s->next != NULL){
		cout << s->next->data << " ";
		s = s->next;	
	}
}
 
//两个链表都是递增的链表 
int main(void){
	int arrA[13] = {2, 4, 5, 7, 11, 23, 24, 50, 56, 77, 88, 99, 100};
	int arrB[8] = {2, 4, 23, 43, 45, 55, 56, 100};
	create(A, B, arrA, 13, arrB, 8); 
	difference(A, B);
	return 0;
}