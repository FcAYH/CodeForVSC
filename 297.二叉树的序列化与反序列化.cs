/*
 * @lc app=leetcode.cn id=297 lang=csharp
 *
 * [297] 二叉树的序列化与反序列化
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
public class Codec
{
    private string treeCode = "";
    private string[] tempCode;
    private int index;
    private void InCodeByDfs(TreeNode poi)
    {
        if (poi.left != null)
        {
            treeCode += "," + poi.left.val;
            InCodeByDfs(poi.left);
        }
        else
        {
            treeCode += ",null";
        }

        if (poi.right != null)
        {
            treeCode += "," + poi.right.val;
            InCodeByDfs(poi.right);
        }
        else
        {
            treeCode += ",null";
        }
    }

    // Encodes a tree to a single string.
    public string serialize(TreeNode root)
    {
        if (root != null)
        {
            treeCode += "" + root.val;
            InCodeByDfs(root);
        }
        //Console.WriteLine(treeCode);
        return treeCode;
    }

    private void DeCodeByDfs(TreeNode poi)
    {
        if (tempCode[index] != "null")
        {
            TreeNode newNode = new(Convert.ToInt32(tempCode[index]));
            poi.left = newNode;
            index++;
            DeCodeByDfs(newNode);
        }
        else
        {
            index++;
        }

        if (tempCode[index] != "null")
        {
            TreeNode newNode = new(Convert.ToInt32(tempCode[index]));
            poi.right = newNode;
            index++;
            DeCodeByDfs(newNode);
        }
        else
        {
            index++;
        }
    }

    private TreeNode BuildTree()
    {
        TreeNode root = new(Convert.ToInt32(tempCode[0]));
        index = 1;
        DeCodeByDfs(root);
        return root;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(string data)
    {
        if (data != "")
        {
            tempCode = data.Split(',');
            return BuildTree();
        }
        else
        {
            return null;
        }
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));
// @lc code=end

