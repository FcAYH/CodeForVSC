struct ListNode
{
    int value;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

struct ListNode *merge(struct ListNode *ln1, struct ListNode *ln2)
{
    ListNode *preHead = new ListNode();
    ListNode *pre = preHead;

    while (ln1 != nullptr && ln2 != nullptr)
    {
        if (ln1->value < ln2->value)
        {
            pre->next = ln1;
            ln1 = ln1->next;
        }
        else
        {
            pre->next = ln2;
            ln2 = ln2->next;
        }
        pre = pre->next;
    }

    pre->next = (ln1 == nullptr) ? ln2 : ln1;

    return preHead->next;
};
