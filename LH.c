#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int val;
    TreeNode *lChild;
    TreeNode *rChild;
    int count;
} TreeNode;

// main => flag
void FindTopK(TreeNode *t, int k)
{
    if (t->lChild && t->lChild->count >= k) // top k -> l
    {
        FindTopK(t->lChild, k);
    }
    else // self + r
    {
        int nextK = k;
        if (t->lChild)
            nextK -= t->lChild->count;

        if (nextK == 1)
            printf("%d", t->val);

        else if (t->rChild)
        {
            FindTopK(t->rChild, nextK - 1);
        }
    }
}

int main()
{
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));

    dfs(root, 1);

    free(root);
}
