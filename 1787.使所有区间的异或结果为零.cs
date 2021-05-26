/*
 * @lc app=leetcode.cn id=1787 lang=csharp
 *
 * [1787] 使所有区间的异或结果为零
 */

// @lc code=start
public class Solution
{
    public int MinChanges(int[] nums, int k)
    {
        for (int i = 1; i < nums.Length; i++)
            nums[i] ^= nums[i - 1];

        int Ans = 0;
        int prefix = 0;

        for (int i = k - 1; i < nums.Length; i++)
        {
            if (i == k - 1)
            {
                if (nums[i] != 0)
                {
                    nums[i] = 0;
                    prefix ^= (i == 0) ? 0 : nums[i - 1];
                    Ans++;
                }
            }
            else
            {
                if ((nums[i] ^ nums[i - k] ^ prefix) != 0)
                {
                    nums[i] ^= nums[i - k] ^ nums[i - 1];
                    prefix ^= nums[i - 1] ^ nums[i - k];
                    Ans++;
                }
            }
        }

        return Ans;
    }
}
// @lc code=end

