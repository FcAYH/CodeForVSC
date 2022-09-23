#include <bits/stdc++.h>

using namespace std;

struct LNode
{
    int val;
    LNode *next;

    LNode(int val) : val(val)
    {
        this->next = nullptr;
    }
};

void printList(LNode *head)
{
    while (head != nullptr)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}

void Solve()
{
    LNode *head = new LNode(1);
    LNode *cur = head;
    for (int i = 2; i <= 6; i++)
    {
        LNode *node = new LNode(i);
        cur->next = node;
        cur = node;
    }

    int length = 6;
    // printList(head);

    cur = head;
    int cnt = 1;
    LNode *preNode = cur;
    while (cnt <= (length + 1) / 2)
    {
        preNode = cur;
        cur = cur->next;
        cnt++;
    }

    preNode->next = nullptr;
    // printList(head);

    LNode *secListHead = cur;
    preNode = cur;
    cur = cur->next;
    preNode->next = nullptr;

    while (cur != nullptr)
    {
        LNode *nextNode = cur->next;
        cur->next = preNode;
        preNode = cur;
        cur = nextNode;
    }
    secListHead = preNode;

    // printList(secListHead);

    cur = head;
    while (cur != nullptr && secListHead != nullptr)
    {
        LNode *nextNode = cur->next;
        cur->next = secListHead;

        LNode *nextHead = secListHead->next;
        secListHead->next = nextNode;
        secListHead = nextHead;
        cur = nextNode;
    }

    printList(head);
}

int main()
{
    Solve();

    return 0;
}
