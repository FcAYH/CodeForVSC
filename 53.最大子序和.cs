/*
 * @lc app=leetcode.cn id=53 lang=csharp
 *
 * [53] 最大子序和
 */

// @lc code=start
public class Solution
{
    int Inf = 0x3f3f3f3f;
    public int MaxSubArray(int[] nums)
    {
        int Ans = -Inf, temp = -Inf;
        foreach (int i in nums)
        {
            temp = Math.Max(i, i + temp);
            Ans = Math.Max(Ans, temp);
        }

        return Ans;
    }
}
// @lc code=end

