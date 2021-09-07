#include <stdio.h>
#include <stdlib.h>
struct LNode
{
    int data;
    struct LNode *next;
};
struct LNode *create(int n);
void show(struct LNode *head);
void DeleteMemory(struct LNode *head);
int main()
{
    struct LNode *head = NULL;
    int n;
    printf("输入你想创建的结点个数:");
    scanf("%d", &n);
    head = create(n);
    printf("结果是:\n");
    show(head);
    DeleteMemory(head);
    return 0;
}
struct LNode *create(int n)
{
    struct LNode *head = NULL;
    int i, x;
    printf("输入整数:\n");
    for (i = 0; i < n; i++)
    {
        struct LNode *p = NULL, *pr = head;
        scanf("%d", &x);
        p = (struct LNode *)malloc(sizeof(struct LNode));
        p->data = x;
        p->next = NULL;
        if (head == NULL)
        {
            head = p;
        }
        else
        {
            while (pr->next != NULL)
            {
                pr = pr->next;
            }
            pr->next = p;
        }
    }
    return head;
}
void show(struct LNode *head)
{
    struct LNode *p = head;
    while (p != NULL)
    {
        printf("%d  ", p->data);
        p = p->next;
    }
}
void DeleteMemory(struct LNode *head)
{
    struct LNode *p = head, *pr = NULL;
    while (p != NULL)
    {
        pr = p;
        p = p->next;
        free(pr);
    }
}
