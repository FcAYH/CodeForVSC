/*
 * @lc app=leetcode.cn id=639 lang=csharp
 *
 * [639] 解码方法 II
 */

// @lc code=start
public class Solution
{
    const int MOD = 1000000007;
    public int NumDecodings(string s)
    {
        int length = s.Length;
        if (length == 0)
            return 0;
        else if (length == 1)
        {
            if (s[0] == '*')
                return 9;
            else if (s[0] != '0')
                return 1;
            else
                return 0;
        }

        int[] dp = new int[length];

        if (s[1] == '*')
            dp[1] = dp[0] * 9;
        else
            dp[1] = dp[0];

        for (int i = 2; i < length; i++)
        {
            if (s[i] == '*')
                dp[i] = dp[i - 1] * 9;
            else
                dp[i] = dp[i - 1];

            if (s[i - 1] == '*')
            {
                if (s[i] == '*')
                    dp[i] += 17;
                else if (s[i] <= '6')
                    dp[i] += 2;
                else
                    dp[i] += 1;
            }
            else if (s[i - 1] == '1')
            {
                if (s[i] == '*')
                    dp[i] += 10;
                else
                    dp[i] += 1;
            }
            else if (s[i - 1] == '2')
            {
                if (s[i] == '*')
                    dp[i] += 7;
                else if (s[i] <= '6')
                    dp[i] += 1;
            }
        }

        return dp[length - 1];
    }
}
// @lc code=end

