#include <stdio.h>
#include <stdlib.h>

#define QueueSize 8

//循环队列
typedef struct CircularQueue
{
    char *array; //顺序表
    int front, rear;
    int count; //顺序表大小
} CircularQueue;

//队列的创建与初始化
void CircularQUeue_Init(CircularQueue *L)
{
    L->array = (char *)malloc((QueueSize + 1) * sizeof(char));
    L->count = 0;
    L->front = 1, L->rear = 0;
}

//在队尾添加元素
void CircularQueue_Push(CircularQueue *L, char Element)
{
    //判断队列是否已满
    if (L->count == QueueSize)
    {
        printf("The Queue is full, you can't push new element now!\n");
        return;
    }

    //插入元素
    (L->rear == QueueSize) ? L->rear = 1 : L->rear++;
    L->array[L->rear] = Element;
    L->count++;
    printf("Push element Complete.\n");
}

//将队首元素出队
void CircularQueue_Pop(CircularQueue *L)
{
    //判断队列是否空
    if (!L->count)
    {
        printf("The Queue is empty, there is no element to pop!\n");
        return;
    }

    printf("%c\n", L->array[L->front]);
    (L->front == QueueSize) ? L->front = 1 : L->front++;
    L->count--;
}

//将队列中剩余元素依次出队
void CircularQueue_Clear(CircularQueue *L)
{
    while (L->count)
        CircularQueue_Pop(L);
}

//释放内存
void CircularQueue_Free(CircularQueue *L)
{
    free(L->array);
}

//读入数据
char GetElement()
{
    char ch = getchar();
    //略过空格和换行
    while (ch == '\n' || ch == ' ')
        ch = getchar();

    return ch;
}

//输入菜单界面
void Print_Welcome_desk()
{
    printf(" Welcome\n\n");
    printf("    You can input almost every character, and it will be push at the back of the Queue.\n\n");
    printf(" These are characters we support:\n\n");
    printf("     Both uppercase and Lowercase letters, Numbers from 0 to 9, ',', '.', '/',\n\n");
    printf("    ';', '<', '>', '?', ':', '[', ']', '{', '}', '-', '=', '_', '+', '~','!',\n\n");
    printf("    '$', '^', '&', '*', '(', ')'.  \n\n");
    printf(" Attention: \n\n   The character '#' means pop an element from the Queue, \n\n");
    printf("   The character '@' means pop all of the element from the Queue one by one,\n\n");
    printf("   The character '`' means end operation. \n\n");
}
//输出退出界面
void Print_Goodbye_desk()
{
    printf("Goodbye\n");
}

void Solve()
{
    Print_Welcome_desk();

    //循环队列
    CircularQueue L;
    CircularQUeue_Init(&L);

    while (1)
    {
        int Isend = 0; //判断程序是否终止

        //读入数据
        char ch;
        ch = GetElement();
        while (ch == '\\' || ch == ' \' ' || ch == '\"')
        {
            ch = GetElement();
        }

        //判断操作类型
        switch (ch)
        {
        case '#':
            CircularQueue_Pop(&L);
            break;
        case '@':
            CircularQueue_Clear(&L);
            break;
        case '`':
            Isend = 1;
            break;
        default:
            CircularQueue_Push(&L, ch);
            break;
        }
        if (Isend)
            break;
    }

    CircularQueue_Free(&L);

    Print_Goodbye_desk();
}

int main()
{
    Solve();

    system("pause");

    return 0;
}
// 1 2 3 4 a r d #
