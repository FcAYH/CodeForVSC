using System.Collections.Generic;
/*
 * @lc app=leetcode.cn id=446 lang=csharp
 *
 * [446] 等差数列划分 II - 子序列
 */

// @lc code=start
public class Solution
{
    public int NumberOfArithmeticSlices(int[] nums)
    {
        int length = nums.Length;
        if (length < 3)
            return 0;

        Dictionary<long, int>[] dict = new Dictionary<long, int>[length];
        for (int i = 0; i < length; i++)
            dict[i] = new Dictionary<long, int>();

        int ans = 0;
        for (int i = 1; i < length; i++)
        {
            for (int j = 0; j < i; j++)
            {
                long dictKey = (long)nums[i] - (long)nums[j];
                int dictValue = dict[j].ContainsKey(dictKey) ? dict[j][dictKey] : 0;

                ans += dictValue;

                if (dict[i].ContainsKey(dictKey) == false)
                    dict[i].Add(dictKey, dictValue + 1);
                else
                    dict[i][dictKey] += dictValue + 1;
            }
        }

        return ans;
    }
}
// @lc code=end

//[0,2000000000,-294967296]
//[0, 1, 2]
