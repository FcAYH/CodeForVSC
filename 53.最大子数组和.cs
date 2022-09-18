/*
 * @lc app=leetcode.cn id=53 lang=csharp
 *
 * [53] 最大子数组和
 */

// @lc code=start
public class Solution
{
    const int Inf = 0x3f3f3f3f;
    public int MaxSubArray(int[] nums)
    {
        // int[] dp = new int[nums.Length];
        // dp[0] = nums[0];

        // int ans = dp[0];
        // for (int i = 1; i < nums.Length; i++)
        // {
        //     dp[i] = Math.Max(dp[i - 1] + nums[i], nums[i]);
        //     ans = Math.Max(ans, dp[i]);
        // }

        int dpVal = nums[0], ans = nums[0];
        for (int i = 1; i < nums.Length; i++)
        {
            dpVal = Math.Max(dpVal + nums[i], nums[i]);
            ans = Math.Max(ans, dpVal);
        }

        return ans;
    }
}
// @lc code=end

