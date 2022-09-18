/*
 * @lc app=leetcode.cn id=450 lang=csharp
 *
 * [450] 删除二叉搜索树中的节点
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution
{
    private TreeNode newRoot;
    private void FindAndDelete(TreeNode? fatherNode, TreeNode nowNode, int key)
    {
        if (nowNode.val < key)
        {
            if (nowNode.right != null)
            {
                FindAndDelete(nowNode, nowNode.right, key);
            }
        }
        else if (nowNode.val > key)
        {
            if (nowNode.left != null)
            {
                FindAndDelete(nowNode, nowNode.left, key);
            }
        }
        else
        {
            if (fatherNode != null)
            {
                if (fatherNode.left == nowNode)
                {
                    if (nowNode.left != null && nowNode.right != null)
                    {
                        fatherNode.left = nowNode.left;
                        TreeNode tempNode = nowNode.left;
                        while (tempNode.right != null)
                        {
                            tempNode = tempNode.right;
                        }
                        tempNode.right = nowNode.right;
                    }
                    else if (nowNode.right == null)
                    {
                        fatherNode.left = nowNode.left;
                    }
                    else if (nowNode.left == null)
                    {
                        fatherNode.left = nowNode.right;
                    }
                }
                else
                {
                    if (nowNode.left != null && nowNode.right != null)
                    {
                        fatherNode.right = nowNode.left;
                        TreeNode tempNode = nowNode.left;
                        while (tempNode.right != null)
                        {
                            tempNode = tempNode.right;
                        }
                        tempNode.right = nowNode.right;
                    }
                    else if (nowNode.right == null)
                    {
                        fatherNode.right = nowNode.left;
                    }
                    else if (nowNode.left == null)
                    {
                        fatherNode.right = nowNode.right;
                    }
                }
            }
            else
            {
                newRoot = nowNode.left;
                if (nowNode.left != null && nowNode.right != null)
                {
                    TreeNode tempNode = nowNode.left;
                    while (tempNode.right != null)
                    {
                        tempNode = tempNode.right;
                    }
                    tempNode.right = nowNode.right;
                }
                else if (nowNode.right == null)
                {
                    newRoot = nowNode.left;
                }
                else if (nowNode.left == null)
                {
                    newRoot = nowNode.right;
                }
            }
        }
    }
    public TreeNode DeleteNode(TreeNode root, int key)
    {
        if (root == null)
        {
            return null;
        }
        if (root.val == key && root.left == null && root.right == null)
        {
            return null;
        }
        newRoot = root;
        FindAndDelete(null, root, key);
        return newRoot;
    }
}
// @lc code=end

