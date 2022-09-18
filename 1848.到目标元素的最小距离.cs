/*
 * @lc app=leetcode.cn id=1848 lang=csharp
 *
 * [1848] 到目标元素的最小距离
 */

// @lc code=start
public class Solution
{
    const int Inf = 0x3f3f3f3f;
    public int GetMinDistance(int[] nums, int target, int start)
    {
        int Ans = Inf;
        for (int i = 0; i < nums.Length; i++)
            if (nums[i] == target)
                Ans = Math.Min(Ans, Math.Abs(i - start));

        return Ans;
    }
}
// @lc code=end

