/*有一批共n个集装箱要装上2艘重量分别为c1和c2的轮船，其中集装箱i的重量为wi，满足w1+w2+...+wn<c1+c2。
    基本思路：尽可能将第一艘船装满，如果剩余的货物和小于等于第二艘船的容积，则可以放下，否则无法放下。
    目标：对第一艘船装载时的优化问题。
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct QNode
{
    int data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} Queue;

int initQueue(Queue &Q)
{
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q.front)
        return -1;
    Q.front->next = NULL;

    return 1;
}

int emptyQueue(Queue Q)
{
    if (Q.front == Q.rear)
        return 1;
    else
        return 0;
}

int destroyQueue(Queue &Q)
{
    while (Q.front)
    {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
    return 1;
}

int enQueue(Queue &Q, int ele)
{
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)
        return -1;
    p->data = ele;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;

    return 1;
}

int deQueue(Queue &Q, int &ele)
{
    QueuePtr p;
    if (Q.front == Q.rear)
        return -1;
    p = Q.front->next;
    ele = p->data;
    Q.front->next = p->next;

    if (Q.rear == p)
        Q.rear = Q.front;

    free(p);

    return 1;
}

Queue loadingQueue;
int bestw, n;

void inQueue(int wt, int i)
{
    if (i == n - 1)
    {
        if (wt > bestw)
            bestw = wt;
    }
    else
        enQueue(loadingQueue, wt);
}

int main()
{

    int i, j, k;
    int *w, ew;
    int c;

    printf("input the number of things and the volume of ships:");
    scanf("%d%d", &n, &c);

    w = new int[n];
    printf("input the weights:");

    for (i = 0; i < n; i++)
        scanf("%d", &w[i]);

    initQueue(loadingQueue);
    enQueue(loadingQueue, -1);

    i = 0;  //层数
    ew = 0; //扩展结点对应的载重量

    while (true)
    {
        if (ew + w[i] <= c)
            inQueue(ew + w[i], i);
        inQueue(ew, i);

        deQueue(loadingQueue, ew);

        if (ew == -1) //同层结点尾部
        {
            if (emptyQueue(loadingQueue))
            {
                printf("the result is %d.\n", bestw);
            }

            enQueue(loadingQueue, -1);
            deQueue(loadingQueue, ew);
            i++;
        }
    }

    return 0;
}
