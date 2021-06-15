/*
 * @lc app=leetcode.cn id=278 lang=csharp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
/* The isBadVersion API is defined in the parent class VersionControl.
      bool IsBadVersion(int version); */

public class Solution : VersionControl
{
    public int FirstBadVersion(int n)
    {
        int left = 1, right = n, Ans = 1;

        while (left <= right)
        {
            int mid = (left + right) >> 1;

            if (IsBadVersion(mid) == true)
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

