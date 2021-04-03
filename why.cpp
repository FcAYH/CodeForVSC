#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <queue>
#include <ctime>
#include <set>
#include <vector>
#include <iomanip>
#include <cassert>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *nxt;
} Lnode, *LinkList;

int read()
{
    int rt = 0, in = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            in = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        rt = rt * 10 + ch - '0';
        ch = getchar();
    }
    return rt * in;
}
bool Creat(LinkList q, int n)
{
    if (n < 1)
        return 0;
    for (int i = 1; i <= n; i++)
    {
        printf("Input %d element : ", i);
        LinkList p = (LinkList)malloc(sizeof(LNode));
        p->data = read();
        p->nxt = q->nxt;
        q->nxt = p;
        q = q->nxt;
    }
    return 1;
}
void Delete(LinkList q, int Min, int Max)
{
    while (q->nxt != NULL)
    {
        LinkList p;
        p = (LinkList)malloc(sizeof(LNode));
        p->data = q->data;
        p->nxt = q->nxt;
        while ((p->nxt->data < Min || p->nxt->data > Max) && p->nxt != NULL)
            printf("%d\n", p->nxt->data), p = p->nxt;
        if (p->nxt == NULL)
            break;
        q->nxt = p;
        q = q->nxt->nxt;
        //printf("%d ", q->nxt->data);
    }
}
void Print(LinkList q)
{
    int cnt = 0;
    while (q->nxt != 0)
    {
        q = q->nxt;
        printf("\nThe %d element is %d", ++cnt, q->data);
        cout << 2 << endl;
    }
}
int main()
{
    LinkList head;
    head = (LinkList)malloc(sizeof(LNode));
    head->nxt = 0;
    printf("The number of elements are : ");
    int n = read();
    while (Creat(head, n) == 0)
        n = read();
    printf("\n\nSucceed!\n\n");
    printf("The minimum limitation is ");
    int Min = read();
    printf("The maximum limitation is ");
    int Max = read();
    Delete(head, Min, Max);
    printf("\n\nSucceed!\n\n");
    //Print(head);
    system("pause");
    return 0;
}
// 10 1 2 3 4 5 6 7 8 9 10 4 6