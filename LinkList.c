#include <stdio.h>
#include <stdlib.h>

#define Size 20

//链表节点
typedef struct LNode
{
    int data;           //记录节点数据
    struct LNode *next; //记录节点后继
} LNode;

//链表
typedef struct LinkList
{
    LNode *Head; //头指针
    LNode *Tail; //尾指针
    int count;   //记录链表长度
} LinkList;

void LinkList_Init(LinkList *L) //线性表的创建
{
    L->count = 0; //初始化线性表大小
}

void LinkList_Insert_First_Element(LinkList *L, int Element)
{
    LNode *p = NULL;
    p = (LNode *)malloc(sizeof(LNode));
    p->next = NULL, p->data = Element;
    L->Head->next = p;
    L->Tail = p;
    L->count++;
}

void LinkList_Insert(LinkList *L, int Element) //在顺序表中插入初始元素
{
    //检测元素个数是否达到上限
    if (L->count == 20)
    {
        printf("抱歉,现已达到线性表存储上限,无法插入新元素.\n");
        return;
    }

    //插入元素
    LNode *p = NULL;
    p = (LNode *)malloc(sizeof(LNode));
    p->next = NULL, p->data = Element;
    L->Tail->next = p;
    L->Tail = p;
    L->count++;
}

void LinkList_Insert_At_I(LinkList *L, int pos, int Element) //在pos前插入Element
{
    //检测元素个数是否达到上限
    if (L->count == 20)
    {
        printf("抱歉,现已达到线性表存储上限,无法插入新元素.\n");
        return;
    }
    //检测pos是否合法
    if (pos > L->count - 1 || pos < 0)
    {
        printf("抱歉,当前线性表中不含第 %d 个元素.\n", pos);
        return;
    }

    //查找到next为pos的节点
    int Count = -1;
    for (LNode *i = L->Head; i; i = i->next)
    {
        if (Count == pos - 1)
        {
            //在pos前插入Element,并记录当前元素个数
            LNode *p = NULL;
            p = (LNode *)malloc(sizeof(LNode));
            p->data = Element, p->next = i->next;
            i->next = p;
            L->count++;
        }
        Count++;
    }
}

void LinkList_Delete(LinkList *L, int pos) //删除位于pos的元素
{
    //检测pos是否合法
    if (pos > L->count - 1 || pos < 0)
    {
        printf("抱歉,当前线性表中不含第 %d 个元素.\n", pos);
        return;
    }

    //找到next为pos的节点
    int Count = -1;
    for (LNode *i = L->Head; i; i = i->next)
    {
        if (Count == pos - 1)
        {
            //删除位于pos的元素
            LNode *p;
            p = i->next;
            if (i->next->next == NULL)
                L->Tail = i;
            i->next = i->next->next;
            free(p);
            L->count--; //记录当前元素个数
        }
        Count++;
    }
}

void LinkList_Find(LinkList *L, int Element) //查找Element
{
    int flag = 0, Count = 0, pos = 0;
    for (LNode *i = L->Head->next; i; i = i->next)
    {
        if (i->data == Element)
        {
            if (!flag)
            {
                printf("已在当前线性表中找到 %d ;\n", Element);
                printf("   %d 在线性表中的位置为: %d", Element, pos);
                Count++;
            }
            else
            {
                printf(" %d", pos);
                Count++;
            }
            flag = 1;
        }
        pos++;
    }
    if (!flag)
        printf("抱歉，未在当前线性表中找到 %d \n", Element);
    else
        printf("\n当前线性表中共含有 %d 个 %d. \n", Count, Element);
}

void LinkList_Print(LinkList *L) //输出线性表
{
    if (L->count == 0)
        printf("当前线性表为空！\n");
    else
    {
        printf("当前线性表为:\n");
        for (LNode *i = L->Head->next; i; i = i->next)
            printf("%d ", i->data);
        printf("\n线性表中有 %d 个元素.\n", L->count);
    }
}

void LinkList_Print_only_size(LinkList *L) //仅输出线性表的大小
{
    printf("此时线性表中的元素为: %d \n", L->count);
}

void Print_welcome_desk()
{
    printf("欢迎使用本线性表，请先输入线性表的初始元素： （注：多个数请用空格隔开，并以0结尾）\n");
}

void Print_system_desk()
{
    printf("菜单：\n");
    printf("1.	插入元素 -- 输入 i , e , 在线性表第i个元素之前插入元素 e ;\n");
    printf("2.	删除元素 -- 输入 i , 删除线性表第 i 个元素 ;\n");
    printf("3.	查找元素 -- 输入元素值 e , 程序将输出元素 e 在线性表中出现的所有位置号 ;\n");
    printf("4.	显示线性表长度 ;\n");
    printf("5.	结束程序.\n");
    printf("6.	显示菜单.\n");
    printf("使用说明：先输入操作序号,并按照菜单说明输入后续数据.\n");
}

void Print_goodBye_desk()
{
    printf("欢迎您再次使用,再见!\n");
}

void Solve()
{
    Print_welcome_desk();

    //创建线性表
    LinkList L;
    LinkList_Init(&L);

    //输入初始元素
    int Element = 0;
    scanf("%d", &Element);
    LinkList_Insert_First_Element(&L, Element);
    while (Element)
    {
        scanf("%d", &Element);
        if (!Element)
            break;
        LinkList_Insert(&L, Element);
    }

    Print_system_desk();

    //操作
    int operate = 0;
    scanf("%d", &operate);
    while (operate != 5)
    {
        int i = 0, e = 0;
        switch (operate)
        {
        case 1:
            scanf("%d%d", &i, &e);
            LinkList_Insert_At_I(&L, i, e);
            LinkList_Print(&L);
            break;
        case 2:
            scanf("%d", &i);
            LinkList_Delete(&L, i);
            LinkList_Print(&L);
            break;
        case 3:
            scanf("%d", &e);
            LinkList_Find(&L, e);
            break;
        case 4:
            LinkList_Print_only_size(&L);
            break;
        case 6:
            Print_system_desk();
            break;
        default:
            break;
        }
        scanf("%d", &operate);
    }

    Print_goodBye_desk();
}

int main()
{
    Solve();
    return 0;
}
