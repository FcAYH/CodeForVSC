/*
 * @lc app=leetcode.cn id=9 lang=csharp
 *
 * [9] 回文数
 */

// @lc code=start
public class Solution
{
    public bool IsPalindrome(int x)
    {
        if (x < 0)
            return false;

        int rev = 0;
        int tmp_x = x;

        while (tmp_x != 0)
        {
            rev = rev * 10 + tmp_x % 10;
            tmp_x /= 10;
        }

        return (x == rev) ? true : false;
    }
}
// @lc code=end

