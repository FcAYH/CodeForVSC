#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct book
{
    char ID[10];   // 图书编号
    char name[20]; //书名
    struct book *next;
} book;

book *create(book *tail)
{
    // book *p = (book *)malloc(sizeof(book));

    while (1)
    {
        book *p = (book *)malloc(sizeof(book));
        scanf("%s %s", p->ID, p->name);
        //getchar();
        if (strcmp(p->ID, "0") == 0)
        {
            // printf("s ");
            free(p);
            break;
        }
        else
        {
            p->next = NULL;
            tail->next = p;
            tail = p;
        }
    }
    return tail;
}
void Print(book *head)
{

    book *i = head->next;
    for (; i != NULL; i = i->next)
    {
        printf("%s,%s\n", i->ID, i->name);
    }
}
book *Delete(book *head, book *tail)
{
    char n[10];
    printf("请输入要删除图书的编号：\n");
    scanf("%s", n);

    book *i = head->next, *p = head;
    int flag = 1;
    int Flag = 0;
    for (; i != NULL; i = i->next)
    {
        if (i->next == NULL)
        {
            if (strcmp(i->ID, n) == 0)
            {
                p->next = p->next->next;
                free(i);
                flag = 0;
                i = p;
                tail = i;
                Flag = 1;
            }
        }
        if (strcmp(i->ID, n) == 0)
        {
            p->next = p->next->next;
            free(i);
            flag = 0;
            i = p;
            Flag = 1;
        }
        if (flag)
            p = p->next;
    }
    if (!Flag)
        printf("不存在！");
    printf("删除后的链表：\n");
    Print(head);

    return tail;
}
void Free(book *head)
{
    book *p = head->next;
    for (; p != NULL; p = p->next)
    {
        free(head);
        head = p;
    }
    free(head);
}
int main()
{
    book *head = (book *)malloc(sizeof(book));
    head->next = NULL;
    book *tail = head;
    printf("输入图书的编号和书名：\n");
    tail = create(tail);
    printf("创建的链表：\n");
    Print(head);
    while (1)
    {
        int n;
        printf("Input :");
        scanf("%d", &n);
        if (n == -1)
            break;
        tail = Delete(head, tail);
    }

    Free(head);
    return 0;
}
/*


01 c
01 a
02 python
03 java
02 a
01 a
02 5
03 a
01 a
0 0
01
*/
