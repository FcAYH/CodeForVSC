/*
 * @lc app=leetcode.cn id=810 lang=csharp
 *
 * [810] 黑板异或游戏
 */

// @lc code=start
public class Solution
{
    private bool CalcSum(int[] nums)
    {
        for (int i = 1; i < nums.Length; i++)
            nums[0] ^= nums[i];

        return (nums[0] == 0);
    }
    public bool XorGame(int[] nums)
    {
        return (nums.Length % 2 == 0) ? true : CalcSum(nums);
    }
}
// @lc code=end

