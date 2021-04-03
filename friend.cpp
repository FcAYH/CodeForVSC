#include <iostream>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <sys/timeb.h>
using namespace std;

int n;
typedef struct RedType
{
    int key; //待排序序列关键字项
} RedType;

typedef struct SqList
{
    RedType *r; //存储所有的数据元素，0号存储单元用作监视哨
    int Length; //待排序序列的长度
} SqList;

//生成长度为sqListLen的随机整数序列
SqList *CreatRandomSqList(int sqListLen)
{
    SqList *sq = (SqList *)malloc(sizeof(SqList)); //分配存储空间
    sq->Length = sqListLen;                        //输入序列长度
    sq->r = (RedType *)malloc(sizeof(RedType) * (sq->Length + 1));
    srand((unsigned)time(NULL)); //置取随机数种子
    for (int i = 1; i <= sq->Length; i++)
    {
        sq->r[i].key = int(rand()); //生成随机序列
    }
    return sq; //返回序列起始地址
}

bool cmp(RedType a, RedType b)
{
    return a.key < b.key;
}
void keller_qsort(SqList *L, int l, int r)
{
    if (l < r)
    {
        int i = l, j = r, x = L->r[l].key;
        while (i < j)
        {
            while (i < j && L->r[j].key >= x)
            { // 从右向左找第一个小于x的数
                j--;
            }
            if (i < j)
            {
                L->r[i] = L->r[j];
                i++;
            }
            while (i < j && L->r[i].key < x)
            { // 从左向右找第一个大于等于x的数
                i++;
            }
            if (i < j)
            {
                L->r[j] = L->r[i];
                j--;
            }
        }
        L->r[i].key = x;
        keller_qsort(L, l, i - 1); // 递归调用
        keller_qsort(L, i + 1, r);
    }
    return;
}

void Insertsort(SqList *L)
{
    for (int i = 2; i <= L->Length; i++)
    {
        if (L->r[i].key < L->r[i - 1].key)
        {
            L->r[0] = L->r[i];
            int j;
            for (j = i - 1; L->r[0].key < L->r[j].key; j--)
            {
                L->r[j + 1] = L->r[j];
            }
            L->r[j + 1] = L->r[0];
        }
    }
    return;
}

int main()
{
    SqList *L;                     //定义待排序的随机序列
    struct __timeb64 stime, etime; //定义算法执行前和执行后的系统时间
    long long rmtime, rstime;      //定义算法执行时间秒和毫秒
    char ch[20];
    FILE *fp;
    fp = fopen("ans.csv", "w"); //打开结果存储文件
    for (int i = 1000; i <= 100000; i = i + 1000)
    {
        itoa(i, ch, 10);
        strcat(ch, ",");
        fwrite(ch, sizeof(char), strlen(ch), fp); //横坐标转换后写入文件
    }
    fwrite("\n", sizeof(char), 1, fp);
    for (int i = 1000; i <= 100000; i = i + 1000)
    {
        L = CreatRandomSqList(i);
        _ftime64(&stime);
        //sort(L->r+1, L->r + L->Length+1,cmp);        //STL sort
        keller_qsort(L, 1, L->Length); //手写快排
        //Insertsort(L);                               //插入排序
        for (int i = 1; i < L->Length; i++)
        {
            if (L->r[i].key > L->r[i + 1].key)
            {
                cout << "wrong!" << endl; //O(n)判断排序正确性
            }
        }
        _ftime64(&etime);
        free(L->r);
        free(L);
        rstime = etime.time - stime.time;
        rmtime = rstime * 1000;
        rmtime += etime.millitm - stime.millitm;
        itoa(rmtime, ch, 10);
        strcat(ch, ",");
        fwrite(ch, sizeof(char), strlen(ch), fp); //纵坐标转换后写入文件
    }
    fwrite("\n", sizeof(char), 1, fp);
    fclose(fp);
    return 0;
}
