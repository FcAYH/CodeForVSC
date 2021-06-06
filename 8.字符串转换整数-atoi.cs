/*
 * @lc app=leetcode.cn id=8 lang=csharp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
public class Solution
{
    public int MyAtoi(string s)
    {
        int p = 0, Ans = 0, flag = 1;
        while (p < s.Length && s[p] == ' ') p++;
        while (p < s.Length && s[p] < '0' || s[p] > '9')
        {
            if (s[p] == '-') flag = -1;
            p++;
        }
        while (p < s.Length && s[p] >= '0' && s[p] <= '9')
        {
            Ans = Ans * 10 + s[p] - '0';
            p++;
        }

        return Ans * flag;
    }
}
// @lc code=end

