/*
 * @lc app=leetcode.cn id=486 lang=csharp
 *
 * [486] 预测赢家
 */

// @lc code=start
public class Solution
{
    public bool PredictTheWinner(int[] nums)
    {
        if (nums.Length % 2 == 0)
            return true;

        int n = nums.Length;
        int[,] A = new int[n, n];
        for (int i = 0; i < n; i++)
            A[i, i] = nums[i];

        for (int i = 1; i < n; i++)
            for (int j = i - 1; j >= 0; j--)
                A[j, i] = Math.Max(nums[j] - A[j + 1, i], nums[i] - A[j, i - 1]);


        return A[0, n - 1] >= 0;
    }
}
// @lc code=end

