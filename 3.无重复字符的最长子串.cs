/*
 * @lc app=leetcode.cn id=3 lang=csharp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
public class Solution
{
    public int LengthOfLongestSubstring(string s)
    {
        int length = s.Length;
        int ans = 0;
        int left = 0, right = 0;
        int[] vis = new int[128];
        while (right < length)
        {
            vis[(int)s[right]]++;

            while (vis[(int)s[right]] > 1 && left < right)
            {
                vis[(int)s[left]]--;
                left++;
            }
            right++;
            ans = Math.Max(ans, right - left + 1);
        }
        return ans;
    }
}
// @lc code=end

