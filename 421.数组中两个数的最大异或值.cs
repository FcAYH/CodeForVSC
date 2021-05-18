using System.Security.Cryptography;
/*
 * @lc app=leetcode.cn id=421 lang=csharp
 *
 * [421] 数组中两个数的最大异或值
 */

// @lc code=start
public class Solution
{
    private int count = 0;
    private int[,] trie;
    private void BuildNode(int x)
    {
        int root = 0;
        for (int i = 31; i >= 0; i--)
        {
            if ((x & (1 << i)) != 0)
            {
                if (trie[root, 1] == 0)
                    trie[root, 1] = ++count;
                root = trie[root, 1];
            }
            else
            {
                if (trie[root, 0] == 0)
                    trie[root, 0] = ++count;
                root = trie[root, 0];
            }
        }
    }

    private bool Find(int x, int k)
    {
        int root = 0;
        for (int i = 31; i >= 0; i--)
        {
            if ((x & (1 << i)) != 0)
            {
                if (trie[root, 1] == 0)
                    return false;

                root = trie[root, 1];
            }
            else
            {
                if (trie[root, 0] == 0)
                    return false;

                root = trie[root, 0];
            }

            if (i == k) return true;
        }

        return true;
    }
    public int FindMaximumXOR(int[] nums)
    {
        trie = new int[nums.Length * 32, 2];

        foreach (int i in nums)
            BuildNode(i);

        int Ans = 0;

        for (int digit = 31; digit >= 0; digit--)
        {
            foreach (int i in nums)
                if (Find((Ans | (1 << digit)) ^ i, digit))
                    Ans |= (1 << digit);
        }

        return Ans;
    }
}
// @lc code=end

