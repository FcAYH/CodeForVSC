#include <stdio.h>
#include <stdlib.h>
#define Size 20
typedef struct SqList //定义线性表结构体
{
    int *array; //顺序表
    int count;  //顺序表大小
} SqList;
void SqList_Init(SqList *SqL) //线性表的创建
{
    SqL->array = (int *)malloc(Size * sizeof(int));
    if (!SqL->array)
    {
        printf("抱歉,未能正确建立线性表.\n");
        exit(0); //未能成功建立线性表
    }
    SqL->count = 0; //初始化线性表大小
}

void SqList_Insert(SqList *SqL, int Element) //在顺序表中插入初始元素
{
    //检测元素个数是否达到上限
    if (SqL->count == 20)
    {
        printf("抱歉,现已达到线性表存储上限,无法插入新元素.\n");
        return;
    }

    //插入元素
    SqL->array[SqL->count++] = Element;
}

void SqList_Insert_At_I(SqList *SqL, int pos, int Element) //在pos后插入Element
{
    //检测元素个数是否达到上限
    if (SqL->count == 20)
    {
        printf("抱歉,现已达到线性表存储上限,无法插入新元素.\n");
        return;
    }
    //检测pos是否合法
    if (pos > SqL->count - 1 || pos < 0)
    {
        printf("抱歉,当前线性表中不含第 %d 个元素.\n", pos);
        return;
    }

    //在pos及其后元素向后移动
    for (int i = SqL->count - 1; i >= pos; i--)
        SqL->array[i + 1] = SqL->array[i];
    SqL->array[pos] = Element, SqL->count++; //在pos上插入Element,并记录当前元素个数
}

void SqList_Delete(SqList *SqL, int pos) //删除位于pos的元素
{
    //检测pos是否合法
    if (pos > SqL->count - 1 || pos < 0)
    {
        printf("抱歉,当前线性表中不含第 %d 个元素.\n", pos);
        return;
    }

    //将pos后的元素前移
    for (int i = pos + 1; i <= SqL->count - 1; i++)
        SqL->array[i - 1] = SqL->array[i];
    SqL->count--; //记录当前元素个数
}

void SqList_Find(SqList *SqL, int Element) //查找Element
{
    int flag = 0, Count = 0;
    for (int i = 0; i <= SqL->count - 1; i++)
    {
        if (SqL->array[i] == Element)
        {
            if (!flag)
            {
                printf("已在当前线性表中找到 %d ;\n", Element);
                printf("   %d 在线性表中的位置为: %d", Element, i);
                Count++;
            }
            else
            {
                printf(" %d", i);
                Count++;
            }
            flag = 1;
        }
    }
    if (!flag)
        printf("抱歉，未在当前线性表中找到 %d \n", Element);
    else
        printf("\n当前线性表中共含有 %d 个 %d. \n", Count, Element);
}

void SqList_Print(SqList *SqL) //输出线性表
{
    if (SqL->count == 0)
        printf("当前线性表为空！\n");
    else
    {
        printf("当前线性表为:\n");
        for (int i = 0; i <= SqL->count - 1; i++)
            printf("%d ", SqL->array[i]);
        printf("\n线性表中有 %d 个元素.\n", SqL->count);
    }
}

void SqList_Print_only_size(SqList *SqL) //仅输出线性表的大小
{
    printf("此时线性表中的元素为: %d \n", SqL->count);
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
    SqList SqL;
    SqList_Init(&SqL);

    //输入初始元素
    int Element = 0;
    scanf("%d", &Element);
    while (Element)
    {
        SqList_Insert(&SqL, Element);
        scanf("%d", &Element);
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
            SqList_Insert_At_I(&SqL, i, e);
            SqList_Print(&SqL);
            break;
        case 2:
            scanf("%d", &i);
            SqList_Delete(&SqL, i);
            SqList_Print(&SqL);
            break;
        case 3:
            scanf("%d", &e);
            SqList_Find(&SqL, e);
            break;
        case 4:
            SqList_Print_only_size(&SqL);
            break;
        case 6:
            Print_system_desk();
            break;
        default:
            break;
        }
        scanf("%d", &operate);
    }

    free(SqL.array);

    Print_goodBye_desk();
}

int main()
{
    Solve();
    return 0;
}