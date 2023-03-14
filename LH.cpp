#include <bits/stdc++.h>

struct TreeNode
{
    int val;
    TreeNode *lChild;
    TreeNode *rChild;

public:
    TreeNode(int val) : val(val)
    {
        lChild = nullptr;
        rChild = nullptr;
    }
};

void dfs(TreeNode *t)
{
    if (t->lChild != nullptr)
        dfs(t->lChild);

    if (t->rChild != nullptr)
        dfs(t->rChild);
    printf("%d ", t->val);
}
/*
    10
   /  \
  2    5
/  \
7  1


*/

int main()
{
    TreeNode *root = new TreeNode(10);
    root->lChild = new TreeNode(2);
    root->rChild = new TreeNode(5);
    root->lChild->lChild = new TreeNode(7);
    root->lChild->rChild = new TreeNode(1);

    // dfs(root);

    std::stack<TreeNode *> st;
    std::stack<int> layer;
    st.push(root);
    layer.push(0);
    while (!st.empty())
    {
        TreeNode *t = st.top();
        int la = layer.top();

    startPoint:

        if (la == 1)
            goto leftPoint;
        if (la == 2)
            goto endPoint;

        // printf("%d ", t->val); // 前序遍历输出

        if (t->lChild != nullptr)
        {
            st.push(t->lChild);

            layer.pop();
            layer.push(1);
            layer.push(0);

            t = st.top();
            la = layer.top();
            goto startPoint;
        }
    leftPoint:

        // printf("%d ", t->val); // 中序遍历输出
        if (la == 2)
            goto endPoint;

        if (t->rChild != nullptr)
        {
            st.push(t->rChild);

            layer.pop();
            layer.push(2);
            layer.push(0);

            t = st.top();
            la = layer.top();
            goto startPoint;
        }

    endPoint:
        // printf("%d ", t->val); // 后序遍历输出

        st.pop();
        layer.pop();
    }
}
