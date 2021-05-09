/*
 * @lc app=leetcode.cn id=1482 lang=csharp
 *
 * [1482] 制作 m 束花所需的最少天数
 */

// @lc code=start
public class Solution
{
    const int MaxDay = 1000000001;
    private bool check(int Day, ref int[] bloomDay, ref int m, ref int k)
    {
        int cnt = 0, temp = 0;
        for (int i = 0; i < bloomDay.Length; i++)
        {
            if (bloomDay[i] <= Day)
            {
                if (temp == 0) temp++;
                else if (bloomDay[i - 1] <= Day) temp++;
                else temp = 0;
            }
            else temp = 0;

            if (temp == k)
            {
                temp = 0;
                cnt++;
            }
        }
        return cnt >= m;
    }
    public int MinDays(int[] bloomDay, int m, int k)
    {
        if (m * k > bloomDay.Length) return -1;

        int Ans = 0;
        int left = 1, right = MaxDay;
        while (left <= right)
        {
            int mid = (left + right) >> 1;

            if (check(mid, bloomDay, m, k))
            {
                Ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }

        return Ans;
    }
}
// @lc code=end

