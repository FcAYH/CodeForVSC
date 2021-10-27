/*
 * @lc app=leetcode.cn id=236 lang=csharp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution
{
    private const int MAX_NODE = 100010;
    private const int MAX_MUL = 16;
    private int[] depth = new int[MAX_NODE];
    private int counter = 0;
    //Dictionary<Tupple<TreeNode, int>, TreeNode> mul = new Dictionary<Tupple<TreeNode, int>, TreeNode>();
    private Dictionary<int, int> dict = new Dictionary<int, int>();

    /// <summary>
    /// multiplication
    /// </summary>
    private TreeNode[,] mul = new TreeNode[MAX_NODE, MAX_MUL + 1];
    private void DFS(TreeNode poi)
    {
        if (poi.left != null)
        {
            if (dict.ContainsKey(poi.left.val) == false)
                dict.Add(poi.left.val, counter++);

            depth[dict[poi.left.val]] = depth[dict[poi.val]] + 1;
            mul[dict[poi.left.val], 0] = poi;
            DFS(poi.left);
        }
        if (poi.right != null)
        {
            if (dict.ContainsKey(poi.right.val) == false)
                dict.Add(poi.right.val, counter++);

            depth[dict[poi.right.val]] = depth[dict[poi.val]] + 1;
            mul[dict[poi.right.val], 0] = poi;
            DFS(poi.right);
        }
    }
    private void Multiplication()
    {
        for (int i = 1; i <= MAX_MUL; i++)
        {
            foreach (int val in dict.Values)
            {
                if (mul[val, i - 1] != null)
                    mul[val, i] = mul[dict[mul[val, i - 1].val], i - 1];
            }
        }
    }

    private void Swap(ref TreeNode a, ref TreeNode b)
    {
        TreeNode t = a;
        a = b; b = t;
    }
    private TreeNode LCA(TreeNode p, TreeNode q)
    {
        if (depth[dict[p.val]] < depth[dict[q.val]])
            Swap(ref p, ref q);

        int gap = depth[dict[p.val]] - depth[dict[q.val]];
        for (int i = 0; i <= MAX_MUL; i++)
            if (((1 << i) & gap) != 0)
                p = mul[dict[p.val], i];

        if (p == q)
            return p;

        for (int i = MAX_MUL; i >= 0; i--)
        {
            if (mul[dict[p.val], i] != mul[dict[q.val], i])
            {
                p = mul[dict[p.val], i];
                q = mul[dict[q.val], i];
            }
        }

        return mul[dict[p.val], 0];
    }
    public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q)
    {
        dict.Add(root.val, counter++);
        depth[dict[root.val]] = 1;
        DFS(root);
        Multiplication();
        TreeNode ans = LCA(p, q);

        return ans;
    }
}
// @lc code=end

