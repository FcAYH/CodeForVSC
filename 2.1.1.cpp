#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
Status InitList_L(LinkList &L)
{
    *L=(LinkList)malloc(1*sizeof(LNode));
    if(L=NULL) return ERROR;
    L->next=NULL;
}
Status CreatList_L(LinkList &L,int n)
{
    InitList_L(L);
    LinkList s;
    for(int i=1;i<n;i++)
    {
        s=(LinkList)malloc(n*sizeof(LNode));
        if(s=NULL) return ERROR;
        printf("please in put number");
        scanf("%5d",&s->data);
        s->next=L->next;
        L->next=s;
    }
    return OK;
}
Status DestroyList_L(LinkList &L)
{
    LinkList p;
    while(L!=NULL)
    {
        p=L;
        L=L->next;
        free(p);
    }
}
Status ListTraverse_L(LinkList L)
{
    LinkList p;
    p=L->next;
    while(p!=NULL)
    {
        printf("%d,p->data");
        p=p->next;
    }
    return OK;
}
int main()
{
    LinkList L;
    int n;
    printf("Please input the length of the List:\n");
    scanf("%d",&n);
    CreatList_L(L,n);
    ListTraverse_L(L);
    DestroyList_L(L);

    while(1);
    return 0;
}
