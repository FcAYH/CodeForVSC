#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }

    void Print()
    {
        queue<TreeNode *> q;
        q.push(this);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        cout << endl;
    }

    queue<TreeNode *> GetAllNodes()
    {
        queue<TreeNode *> q;
        queue<TreeNode *> temp;
        q.push(this);
        temp.push(this);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left)
            {
                q.push(node->left);
                temp.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
                temp.push(node->right);
            }
        }
        return temp;
    }
};

int postOrder[30];
int inOrder[30];

TreeNode *BuildTree(int i, int left, int right)
{
    int rootVal = postOrder[i];
    TreeNode *root = new TreeNode(rootVal);

    for (int j = left; j <= right; j++)
    {
        if (inOrder[j] == rootVal)
        {
            if (j > left)
                root->left = BuildTree(i - right + j - 1, left, j - 1);
            if (j < right)
                root->right = BuildTree(i - 1, j + 1, right);
            break;
        }
    }

    return root;
}

void Solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> postOrder[i];
    for (int i = 0; i < n; i++)
        cin >> inOrder[i];

    TreeNode *root = BuildTree(n - 1, 0, n - 1);
    root->Print();
    delete root;
}

int main()
{
    Solve();

    return 0;
}
