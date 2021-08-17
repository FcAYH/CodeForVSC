#include <stdio.h>
#include <stdlib.h>

typedef struct Link
{
    int data;
    struct Link *next;
} link;

link *initLink(int n)
{
    int i, x;
    link *head, *p, *t;
    head = (link *)malloc(sizeof(link));
    head->data = 0;
    t = head;
    printf("请输入%d个数据\n", n);
    for (i = 1; i <= n; i++)
    {

        scanf("%d", &x); //创建首元结点和其他节点
        p = (link *)malloc(sizeof(link));
        p->data = x;
        p->next = NULL;
        t->next = p; //t指向它的下一个
        t = t->next; //t变成它的下一个
    }
    return head;
}

link *insertData(link *head, int x)
{
    link *pr = head, *p = head, *temp = NULL;
    p = (link *)malloc(sizeof(link));
    if (p == NULL)
    {
        printf("No enough memory!\n");
        exit(0);
    }
    p->next = NULL;
    p->data = x;
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        while (pr->data < x && pr->next != NULL)
        {
            temp = pr;
            pr = pr->next;
        }
        if (pr->data >= x)
        {
            if (pr == head)
            {
                p->next = head;
                head = p;
            }
            else
            {
                pr = temp;
                p->next = pr->next;
                pr->next = p;
            }
        }
        else
        {
            pr->next = p;
        }
    }
    return head;
}
link *Delete(link *head, int y)
{
    link *p = head, *pr = head;
    while (y != p->data && p->next != NULL)
    {
        pr = p;
        p = p->next;
    }
    if (y == p->data)
    {
        if (p == head)

        {
            head = p->next;
        }
        else
        {
            pr->next = p->next;
        }
        free(p);
    }
    else
    {
        printf("Not found!\n");
    }
    return head;
}
void display(link *head)
{
    link *t = head->next;
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
}
int main(void)
{
    int n;

    link *head;
    printf("请输入个数n:  \n");
    scanf("%d", &n);
    head = initLink(n);
    printf("此时的链表是: \n");
    display(head);
    printf("\n");

    int x;
    printf("Input x:");
    scanf("%d", &x);
    head = insertData(head, x);
    display(head);

    int y;
    printf("Input y:");
    scanf("%d", &y);
    head = Delete(head, y);
    display(head);

    return 0;
}
