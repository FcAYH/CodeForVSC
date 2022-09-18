/*
 * @lc app=leetcode.cn id=215 lang=csharp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
public class Solution
{
    public int FindKthLargest(int[] nums, int k)
    {
        Array.Sort(nums);
        // for (int i = nums.Length - 1; i >= 0; i--)
        // {
        //     k--;
        //     if (k == 0) return nums[i];
        // }

        return nums[nums.Length - k];
    }
}
// @lc code=end

