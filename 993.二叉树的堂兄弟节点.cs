/*
 * @lc app=leetcode.cn id=993 lang=csharp
 *
 * [993] 二叉树的堂兄弟节点
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
    int fatherX, depthX, fatherY, depthY;
    private void dfs(int fatherX, int depthX, int fatherY, int depthY, TreeNode poi, int depth, int x, int y)
    {
        if (poi.left != null)
        {
            if (poi.left.val == x)
            {
                fatherX = poi.val;
                depthX = depth + 1;
            }
            if (poi.left.val == y)
            {
                fatherY = poi.val;
                depthY = depth + 1;
            }

            dfs(fatherX, depthX, fatherY, depthY, poi.left, depth + 1, x, y);
        }

        if (poi.right != null)
        {
            if (poi.right.val == x)
            {
                fatherX = poi.val;
                depthX = depth + 1;
            }
            if (poi.left.val == y)
            {
                fatherY = poi.val;
                depthY = depth + 1;
            }

            dfs(fatherX, depthX, fatherY, depthY, poi.right, depth + 1, x, y);
        }
    }

    public bool IsCousins(TreeNode root, int x, int y)
    {

        dfs(fatherX, depthX, fatherY, depthY, root, 1, x, y);

        if (depthX != depthY || fatherX == fatherY)
            return false;
        return true;
    }
}
// @lc code=end

