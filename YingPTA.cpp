#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
    int data;
    TreeNode *rchild;
    TreeNode *lchild;
};
int post[31];
int in[31];
TreeNode *BuildTree(int n, int left, int right)
{
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->data = post[n];
    for (int i = left; i <= right; i++)
    {
        if (in[i] == post[n] && i > left)
            root->lchild = BuildTree(n - right + i - 1, left, i - 1);
        if (in[i] == post[n] && i < right)
            root->rchild = BuildTree(n - 1, i + 1, right);
    }
    return root;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &in[i]);
    }

    TreeNode *p = BuildTree(n - 1, 0, n - 1);
    queue<TreeNode *> q;
    q.push(p);
    int i = 1;
    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();
        if (i == 1)
            printf("%d", current->data);
        else
            printf(" %d", current->data);
        if (current->lchild != NULL)
            q.push(current->lchild);
        if (current->rchild != NULL)
            q.push(current->rchild);
        i++;
    }
    return 0;
}
