#include <bits/stdc++.h>

using namespace std;

struct LNode
{
    int data;
    LNode *next;

    LNode(int val) : data(val) {}
};

LNode *head;

LNode *Reverse(LNode *head)
{
    if (head->next == nullptr)
        return head;

    LNode *rear = head->next;
    LNode *reHead = Reverse(rear);

    rear->next = head;
    head->next = nullptr;
    return reHead;
}

/*


2 -> 4 -> 6 -> 1 -> 3 -> 7 -> nullptr
2 -> 4 -> 6 -> 1 <- 3 <- 7

2 <- 4 <- 6 <- 1 <- 3 <- 7
  ->
2 -> list;
list -> reverseList  => reHead, rear;
rear -> next = 2;

reHead

*/

void Solve()
{
    LNode *newHead = Reverse(head);

    LNode *cur = newHead;
    while (cur != nullptr)
    {
        cout << cur->data << endl;
        cur = cur->next;
    }
}

int main()
{
    LNode *node1 = new LNode(2);
    LNode *node2 = new LNode(4);
    LNode *node3 = new LNode(6);
    LNode *node4 = new LNode(1);
    LNode *node5 = new LNode(3);
    LNode *node6 = new LNode(7);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = nullptr;

    head = node1;

    Solve();

    return 0;
}

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

void ReverseTree(TreeNode *root)
{
    if (root == nullptr)
        return;

    swap(root->left, root->right);
    ReverseTree(root->left);
    ReverseTree(root->right);
}

/*

   3
 /  \
2    4

       3
     /  \
    4    2
  /  \
2    4

*/
