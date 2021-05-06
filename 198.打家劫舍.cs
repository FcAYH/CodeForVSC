using System;
/*
 * @lc app=leetcode.cn id=198 lang=csharp
 *
 * [198] 打家劫舍
 */

// @lc code=start
public class Solution
{
    public int Rob(int[] nums)
    {
        int length = nums.Length;
        if (length == 0)
            return 0;
        else if (length == 1)
            return nums[0];

        int pre2 = nums[0], pre1 = Math.Max(pre2, nums[1]);
        int now = Math.Max(pre1, pre2);

        for (int i = 2; i < length; i++)
        {
            now = Math.Max(pre1, pre2 + nums[i]);
            pre2 = pre1; pre1 = now;
        }
        return now;
    }
}
// @lc code=end

