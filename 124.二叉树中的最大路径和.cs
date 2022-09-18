using System;
using System.Collections.Generic;
/*
 * @lc app=leetcode.cn id=124 lang=csharp
 *
 * [124] 二叉树中的最大路径和
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
    Dictionary<TreeNode, int> maxRoad = new Dictionary<TreeNode, int>();
    Dictionary<TreeNode, int> endSelf = new Dictionary<TreeNode, int>();

    private void Dfs(TreeNode poi)
    {
        maxRoad.Add(poi, poi.val);
        endSelf.Add(poi, poi.val);

        if (poi.left != null)
        {
            Dfs(poi.left);
            endSelf[poi] = Math.Max(endSelf[poi], endSelf[poi.left] + poi.val);
            maxRoad[poi] = Math.Max(maxRoad[poi], maxRoad[poi.left]);
        }

        if (poi.right != null)
        {
            Dfs(poi.right);
            maxRoad[poi] = Math.Max(maxRoad[poi], maxRoad[poi.right]);
            endSelf[poi] = Math.Max(endSelf[poi], endSelf[poi.right] + poi.val);
        }

        if (poi.left != null && poi.right != null)
        {
            maxRoad[poi] = Math.Max(maxRoad[poi], endSelf[poi.left]
                                        + endSelf[poi.right] + poi.val);
        }
        maxRoad[poi] = Math.Max(maxRoad[poi], endSelf[poi]);
    }

    public int MaxPathSum(TreeNode root)
    {
        Dfs(root);
        return Math.Max(maxRoad[root], endSelf[root]);
    }
}
// @lc code=end

//[1,2]
//[-6,null,3,2]
