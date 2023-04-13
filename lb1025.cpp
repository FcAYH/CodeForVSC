#include <bits/stdc++.h>

using namespace std;
struct LNode
{
    int addr;
    int data;
    int next;
};
LNode mem[101001];
LNode lst[101001];
void rev(int left, int right)
{
    while (left < right)
    {
        swap(lst[left], lst[right]);
        left++, right--;
    }
}

void Solve()
{
    int head;
    scanf("%d", &head);
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        int add;
        scanf("%d", &add);
        mem[add].addr = add;
        scanf("%d%d", &mem[add].data, &mem[add].next);
    }

    int cur = head;
    int index = 0;
    while (cur != -1)
    {
        lst[index] = mem[cur];
        cur = mem[cur].next;
        index++;
    }

    // if (index != n)
    //     return;
    // int c = floor((double)n / (double)k);
    // for (int i = 0; i < c; i++)
    // {
    //     rev(k * i, k * i + k - 1);
    // }

    for (int i = 0; i < index; i += k)
    {
        int left = i, right = i + k - 1;
        if (right >= index)
            break;

        // rev(left, right);
        while (left < right)
        {
            swap(lst[left], lst[right]);
            left++;
            right--;
        }
    }

    for (int i = 0; i < index - 1; i++)
    {
        lst[i].next = lst[i + 1].addr;
    }
    lst[index - 1].next = -1;
    for (int i = 0; i < index; i++)
    {
        if (i == index - 1)
            printf("%05d %d %d\n", lst[i].addr, lst[i].data, lst[i].next);
        else
            printf("%05d %d %05d\n", lst[i].addr, lst[i].data, lst[i].next);
    }
}

int main()
{
    Solve();

    return 0;
}
/*
00100 4 4
00000 4 99999
00100 1 12309
99999 6 -1
12309 3 00000
*/
