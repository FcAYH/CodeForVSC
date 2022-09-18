#include <bits\stdc++.h>

using namespace std;

const bool INFEASIBLE = 0;
const bool OK = 1;
const int Maxn = 100001;

struct SqList
{
    int elem[Maxn];
    int length = 0;
} List;

bool DeleteK(SqList &a, int i, int k) //删除链表中第i个元素起的连续k个元素
{
    if (i < 1 || k < 0 || i + k > a.length)
        return INFEASIBLE;
    for (int j = i + k; j <= a.length; j++)
        a.elem[j - k] = a.elem[j];
    a.length -= k;
    return OK;
}

void InsertX(SqList &a, int x) //在有序链表中插入元素x
{
    for (int i = 1; i <= a.length; i++)
    {
        if (a.elem[i] == x)
        {
            for (int j = a.length; j >= i; j++)
                a.elem[j + 1] = a.elem[j];
            a.elem[i] = x, a.length++;
            break;
        }
    }
}

void ReverseList(SqList &a) //将链表反转
{
    int Length = a.length;
    for (int i = 1; i <= a.length / 2; i++)
        swap(a.elem[i], a.elem[Length - i + 1]);
}

SqList MergeList(const SqList a, const SqList b) //将两个有序链表合并
{
    SqList *c = new SqList;
    int Pointera = 1, Pointerb = 1, Length = 0;
    while (Pointera <= a.length && Pointerb <= b.length)
    {
        c->elem[++Length] = (a.elem[Pointera] < b.elem[Pointerb]) ? a.elem[Pointera++] : b.elem[Pointerb++];
    }
    while (Pointera <= a.length)
        c->elem[++Length] = a.elem[Pointera++];
    while (Pointerb <= b.length)
        c->elem[++Length] = b.elem[Pointerb++];
    c->length = Length;
    return *c;
}

void Solve()
{
}

int main()
{
    Solve();
    system("pause");
    return 0;
}