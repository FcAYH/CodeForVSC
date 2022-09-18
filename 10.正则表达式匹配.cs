/*
 * @lc app=leetcode.cn id=10 lang=csharp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
public class Solution
{
    public bool IsMatch(string s, string p)
    {
        int p1 = 0, p2 = 0;

        while (p1 < s.Length && p2 < p.Length)
        {
            if (s[p1] == p[p2] || p[p2] == '.')
            {
                p1++; p2++;
            }
            else if (p[p2] == '*')
            {

                char temp = s[p1 - 1];
                while (s[p1] == temp) p1++;
                p2++;
            }
            else if (p2 + 1 < p.Length && p[p2 + 1] == '*')
                p2 += 2;
            else return false;
        }

        return (p1 == s.Length) ? true : false;
    }
}
// @lc code=end

