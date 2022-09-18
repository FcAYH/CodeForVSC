/*
 * @lc app=leetcode.cn id=1854 lang=csharp
 *
 * [1854] 人口最多的年份
 */

// @lc code=start
public class Solution
{
    public int MaximumPopulation(int[][] logs)
    {
        int Ans = 0;
        int ansYear = 0;

        for (int year = 1950; year <= 2050; year++)
        {
            int cnt = 0;
            for (int i = 0; i < logs.Length; i++)
            {
                if (logs[i][0] <= year && logs[i][1] > year)
                    cnt++;
            }

            if (cnt > Ans)
            {
                Ans = cnt; ansYear = year;
            }
        }

        return ansYear;
    }
}
// @lc code=end

