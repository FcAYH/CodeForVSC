using System;
/*
 * @lc app=leetcode.cn id=474 lang=csharp
 *
 * [474] 一和零
 */

// @lc code=start
public class Solution
{
    public int FindMaxForm(string[] strs, int m, int n)
    {
        int[,] numbers = new int[strs.Length, 2];

        for (int i = 0; i < strs.Length; i++)
            for (int j = 0; j < strs[i].Length; j++)
                numbers[i, strs[i][j] - '0']++;

        int[,] A = new int[m + 1, n + 1];
        for (int i = 0; i < strs.Length; i++)
            for (int j = m; j >= numbers[i, 0]; j--)
                for (int k = n; k >= numbers[i, 1]; k--)
                    A[j, k] = Math.Max(A[j, k], A[j - numbers[i, 0], k - numbers[i, 1]] + 1);

        return A[m, n];
    }
}
// @lc code=end

