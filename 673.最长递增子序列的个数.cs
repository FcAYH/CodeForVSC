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
        int maxLength = 1;
        int[] LISLength = new int[nums.Length];
        int[] LISCount = new int[nums.Length];

        LISLength[0] = 1;
        LISCount[0] = 1;
        for (int i = 1; i < nums.Length; i++)
        {
            LISLength[i] = 1;
            LISCount[i] = 1;

            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    if (LISLength[i] == LISLength[j] + 1)
                    {
                        LISCount[i] += LISCount[j];
                    }

                    if (LISLength[i] < LISLength[j] + 1)
                    {
                        LISLength[i] = LISLength[j] + 1;
                        LISCount[i] = LISCount[j];
                    }
                }
            }

            maxLength = Math.Max(maxLength, LISLength[i]);
        }

        int count = 0;
        for (int i = 0; i < nums.Length; i++)
        {
            if (LISLength[i] == maxLength)
                count += LISCount[i];
        }

        return count;
    }
}
// @lc code=end

//[2,5,1,3,6,7,8,53,2,3,62,28,3,5,542,6]
