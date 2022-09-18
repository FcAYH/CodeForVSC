/*
 * @lc app=leetcode.cn id=1449 lang=csharp
 *
 * [1449] 数位成本和为目标值的最大数字
 */

// @lc code=start
public class Solution
{
    public string LargestNumber(int[] cost, int target)
    {
        int[] dp = new int[target + 1];
        Array.Fill(dp, int.MinValue);
        dp[0] = 0;

        foreach (int c in cost)
            for (int j = c; j <= target; ++j)
                dp[j] = Math.Max(dp[j], dp[j - c] + 1);



        if (dp[target] < 0)
            return "0";

        StringBuilder sb = new StringBuilder();
        for (int i = 8, j = target; i >= 0; i--)
            for (int c = cost[i]; j >= c && dp[j] == dp[j - c] + 1; j -= c)
                sb.Append(i + 1);

        return sb.ToString();
    }
}
// @lc code=end

