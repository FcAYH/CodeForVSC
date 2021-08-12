/*
 * @lc app=leetcode.cn id=516 lang=csharp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
public class Solution
{
    public int LongestPalindromeSubseq(string s)
    {
        int length = s.Length;
        int[,] A = new int[length, length];

        for (int i = 0; i < length; i++)
            A[i, i] = 1;

        for (int j = 1; j < length; j++)
        {
            for (int i = 0; i < j; i++)
            {
                if (s[i] == s[j])
                    A[i, j] = A[i + 1, j - 1] + 1;

                A[i, j] = Math.Max(A[i + 1, j], A[i, j + 1]);
            }
        }

        return A[0, length - 1];
    }
}
// @lc code=end

