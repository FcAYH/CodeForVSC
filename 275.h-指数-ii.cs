/*
 * @lc app=leetcode.cn id=275 lang=csharp
 *
 * [275] H 指数 II
 */

// @lc code=start
public class Solution
{
    public int HIndex(int[] citations)
    {
        int length = citations.Length;
        int left = 0, right = citations.Length - 1;

        int Ans = 0;
        while (left <= right)
        {
            int mid = (left + right) >> 1;

            if (citations[mid] < length - mid)
                left = mid + 1;
            else
            {
                Ans = length - mid;
                right = mid - 1;
            }
        }

        return Ans;
    }
}
// @lc code=end

