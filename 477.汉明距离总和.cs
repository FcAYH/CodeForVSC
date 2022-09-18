/*
 * @lc app=leetcode.cn id=477 lang=csharp
 *
 * [477] 汉明距离总和
 */

// @lc code=start
public class Solution
{
    public int TotalHammingDistance(int[] nums)
    {
        int[] sum = new int[32];

        for (int i = 30; i >= 0; i--)
        {
            if (((1 << i) & nums[0]) != 0)
                sum[i]++;
        }

        int Ans = 0;
        for (int i = 1; i < nums.Length; i++)
        {
            for (int j = 30; j >= 0; j--)
            {
                if (((1 << j) & nums[i]) == 0)
                    Ans += sum[j];
                else
                {
                    Ans += i - sum[j];
                    sum[j]++;
                }
            }
        }

        return Ans;
    }
}
// @lc code=end

/*
000100
001110
000010

[3,4,1,5,6,9,23,14,0]
*/
