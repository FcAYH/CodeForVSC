/*
 * @lc app=leetcode.cn id=7 lang=csharp
 *
 * [7] 整数反转
 */

// @lc code=start
public class Solution
{
    public int Reverse(int x)
    {
        int flag = 1;
        if (x < 0) flag = -1;

        if (x == -2147483648)
            return 0;

        if (x < 0) x = -x;

        int rev = 0;

        while (x != 0)
        {
            if (rev > int.MaxValue / 10 || rev == int.MaxValue / 10 && x > 7)
                return 0;
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        return flag * rev;
    }
}
// @lc code=end

