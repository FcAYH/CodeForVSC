/*
 * @lc app=leetcode.cn id=1482 lang=csharp
 *
 * [1482] 制作 m 束花所需的最少天数
 */

// @lc code=start
public class Solution
{
    const int MaxDay = 1000000001;
    public int MinDays(int[] bloomDay, int m, int k)
    {
        if (m * k > bloomDay.Length) return -1;

        int left = 1, right = MaxDay;


    }
}
// @lc code=end

