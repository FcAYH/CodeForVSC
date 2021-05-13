/*
 * @lc app=leetcode.cn id=1855 lang=csharp
 *
 * [1855] 下标对中的最大距离
 */

// @lc code=start
public class Solution
{
    public int MaxDistance(int[] nums1, int[] nums2)
    {
        int p1 = 0, p2 = 0;
        int Ans = 0;

        for (p1 = 0; p1 < nums1.Length; p1++)
        {
            while (p2 < nums2.Length && nums2[p2] >= nums1[p1] || p2 < p1)
            {
                Ans = Math.Max(Ans, p2 - p1);
                p2++;
            }

        }

        return Ans;
    }
}
// @lc code=end

