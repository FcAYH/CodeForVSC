/*
 * @lc app=leetcode.cn id=673 lang=csharp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
public class Solution
{
    public int FindNumberOfLIS(int[] nums)
    {
        int tempMaxValue = 0;
        int tempCount = 0;
        int[] LIS = new int[nums.Length];

        LIS[0] = 1;
        for (int i = 1; i < nums.Length; i++)
        {
            LIS[i] = 1;

            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    LIS[i] = Math.Max(LIS[i], LIS[j] + 1);

                if (LIS[i] > tempMaxValue)
                {
                    tempMaxValue = LIS[i];

                    tempCount = 1;
                }
                else if (LIS[i] == tempMaxValue)
                    tempCount++;
            }
        }

        return tempCount;
    }
}
// @lc code=end

