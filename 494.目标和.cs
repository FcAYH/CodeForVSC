/*
 * @lc app=leetcode.cn id=494 lang=csharp
 *
 * [494] 目标和
 */

// @lc code=start
public class Solution
{
    private int[] prefix;
    private int n, target, Ans = 0;
    private void dfs(int pos, int sum)
    {
        if (pos == n + 1)
        {
            if (sum == target)
                Ans++;
            return;
        }

        if (sum > target && sum - (prefix[n] - prefix[pos - 1]) > target)
            return;
        if (sum < target && sum + (prefix[n] - prefix[pos - 1]) < target)
            return;

        dfs(pos + 1, sum + prefix[pos] - prefix[pos - 1]);
        dfs(pos + 1, sum - (prefix[pos] - prefix[pos - 1]));
    }
    public int FindTargetSumWays(int[] nums, int target)
    {
        n = nums.Length;
        this.target = target;

        prefix = new int[n + 1];
        prefix[1] = nums[0];
        for (int i = 2; i <= n; i++)
            prefix[i] = prefix[i - 1] + nums[i - 1];

        dfs(1, 0);

        return Ans;
    }
}
// @lc code=end

