/*
 * @lc app=leetcode.cn id=5 lang=csharp
 *
 * [5] 最长回文子串
 */

// @lc code=start
public class Solution
{
    public string LongestPalindrome(string s)
    {
        int ansVal = 1;
        int ansLeft = 0, ansRight = 0;

        for (int i = 1; i < s.Length - 1; i++)
        {
            int nowAns = 0;

            int left = i - 1, right = i + 1;

            while (left >= 0 && right < s.Length)
            {
                if (s[left] == s[right])
                {
                    nowAns += 2;
                    left--; right++;
                }
                else break;
            }

            if (nowAns > ansVal)
            {
                ansVal = nowAns;
                ansLeft = left + 1;
                ansRight = right - 1;
            }
        }

        for (int i = 1; i < s.Length; i++)
        {
            int nowAns = 0;

            int left = i - 1, right = i;

            while (left >= 0 && right < s.Length)
            {
                if (s[left] == s[right])
                {
                    nowAns += 2;
                    left--; right++;
                }
                else break;
            }

            if (nowAns > ansVal)
            {
                ansVal = nowAns;
                ansLeft = left + 1;
                ansRight = right - 1;
            }
        }

        return s.Substring(ansLeft, ansRight - ansLeft + 1);
    }
}
// @lc code=end

